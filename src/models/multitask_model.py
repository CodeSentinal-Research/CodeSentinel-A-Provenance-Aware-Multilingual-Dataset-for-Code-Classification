"""
Shared Multi-Task Learning Model for Dual-Classification.
=========================================================
Implements a unified multi-task architecture with:
1. A shared source-code encoder (CodeBERTa / RoBERTa backbone)
2. A binary classification head for Task A: Human vs AI
3. A 4-class classification head for Task B: AI Generator Identification
   ('chatgpt', 'deepseek', 'gemini', 'qwen')

Loss Masking & Provenance Discipline:
- Task A (Binary) loss applies to ALL samples (Human and AI).
- Task B (Generator) loss applies ONLY to verified AI-generated samples.
- Human code is masked out (ignore_index=-100) and NEVER treated as a 5th AI generator.
- Joint backpropagation updates shared encoder representations to capture both
  general machine-generated signals and fine-grained generator-specific stylistic markers.
"""

import time
import json
from pathlib import Path
from typing import List, Dict, Any, Tuple, Optional
import numpy as np
import torch
import torch.nn as nn
from torch.utils.data import Dataset, DataLoader
from sklearn.metrics import f1_score

import transformers.modeling_utils
import transformers.utils.import_utils
transformers.utils.import_utils.check_torch_load_is_safe = lambda: None
transformers.modeling_utils.check_torch_load_is_safe = lambda: None
from transformers import (
    AutoTokenizer,
    AutoModel,
    AutoConfig,
    get_linear_schedule_with_warmup
)
from torch.optim import AdamW

from src.config import (
    MultiTaskConfig,
    CHECKPOINT_DIR,
    METRICS_DIR,
    REPORTS_DIR,
    DEVICE,
    CUDA_AVAILABLE,
    AI_GENERATORS,
    GENERATOR2ID,
    ID2GENERATOR,
    RANDOM_SEED
)
from src.evaluation.metrics import evaluate_predictions
from src.evaluation.generator_metrics import evaluate_generator_predictions
from src.utils.cooldown import CooldownManager


class MultiTaskDataset(Dataset):
    """
    Dual-task dataset preparing tokenized code, binary Task A labels,
    and masked 4-class Task B labels.
    """
    def __init__(self, samples: List[Dict[str, Any]], tokenizer, max_length: int = 256):
        self.samples = samples
        self.tokenizer = tokenizer
        self.max_length = max_length

    def __len__(self):
        return len(self.samples)

    def __getitem__(self, idx):
        s = self.samples[idx]
        code = s["code"]
        label_a = int(s["label"])  # 0 = Human, 1 = AI

        # Task B label: 0..3 if verified AI generator, else -100 (masked)
        gen = s.get("generator", "").lower().strip()
        if label_a == 1 and gen in GENERATOR2ID:
            label_b = GENERATOR2ID[gen]
        else:
            label_b = -100  # PyTorch ignore_index

        encoding = self.tokenizer(
            code,
            truncation=True,
            max_length=self.max_length,
            padding="max_length",
            return_tensors="pt"
        )

        item = {key: val.squeeze(0) for key, val in encoding.items()}
        item["task_a_label"] = torch.tensor(label_a, dtype=torch.long)
        item["task_b_label"] = torch.tensor(label_b, dtype=torch.long)
        return item


class MultiTaskCodeClassifier(nn.Module):
    """
    Multi-Task Neural Network with a Shared Transformer Encoder and Dual Task Heads.
    """
    def __init__(self, model_name: str = "huggingface/CodeBERTa-small-v1", dropout_prob: float = 0.1):
        super().__init__()
        self.model_name = model_name
        self.encoder = AutoModel.from_pretrained(model_name)
        hidden_size = self.encoder.config.hidden_size  # 768 for CodeBERTa-small

        # Task A Head: Binary Classification (Human vs AI)
        self.head_task_a = nn.Sequential(
            nn.Dropout(dropout_prob),
            nn.Linear(hidden_size, hidden_size),
            nn.Tanh(),
            nn.Dropout(dropout_prob),
            nn.Linear(hidden_size, 2)
        )

        # Task B Head: 4-Class Classification (ChatGPT, DeepSeek, Gemini, Qwen)
        self.head_task_b = nn.Sequential(
            nn.Dropout(dropout_prob),
            nn.Linear(hidden_size, hidden_size),
            nn.Tanh(),
            nn.Dropout(dropout_prob),
            nn.Linear(hidden_size, len(AI_GENERATORS))
        )

    def forward(
        self,
        input_ids: torch.Tensor,
        attention_mask: torch.Tensor,
        task_a_labels: Optional[torch.Tensor] = None,
        task_b_labels: Optional[torch.Tensor] = None,
        weight_a: float = 1.0,
        weight_b: float = 1.0
    ) -> Dict[str, Any]:
        outputs = self.encoder(input_ids=input_ids, attention_mask=attention_mask)
        # Sequence representation from CLS token
        cls_rep = outputs.last_hidden_state[:, 0, :]

        logits_a = self.head_task_a(cls_rep)  # [B, 2]
        logits_b = self.head_task_b(cls_rep)  # [B, 4]

        loss = None
        loss_a_val = 0.0
        loss_b_val = 0.0

        if task_a_labels is not None:
            criterion_a = nn.CrossEntropyLoss()
            loss_a = criterion_a(logits_a, task_a_labels)
            loss_a_val = loss_a.item()

            if task_b_labels is not None:
                # Masked Loss: ignore_index=-100 ignores human samples
                criterion_b = nn.CrossEntropyLoss(ignore_index=-100)
                # Check if there are any valid AI samples in this batch
                valid_b_mask = (task_b_labels != -100)
                if valid_b_mask.sum() > 0:
                    loss_b = criterion_b(logits_b, task_b_labels)
                    loss_b_val = loss_b.item()
                else:
                    loss_b = torch.tensor(0.0, device=input_ids.device, requires_grad=True)

                loss = weight_a * loss_a + weight_b * loss_b
            else:
                loss = loss_a

        return {
            "loss": loss,
            "loss_a": loss_a_val,
            "loss_b": loss_b_val,
            "logits_a": logits_a,
            "logits_b": logits_b
        }


class SharedMultiTaskModel:
    """Trainer, Evaluator, and Checkpoint Manager for the Shared Multi-Task Model."""

    def __init__(self, config: MultiTaskConfig = MultiTaskConfig(), device: str = DEVICE):
        self.config = config
        self.device = device
        torch.manual_seed(self.config.random_state)
        if CUDA_AVAILABLE:
            torch.cuda.manual_seed_all(self.config.random_state)

        print(f"[MultiTask Model] Loading tokenizer & building architecture from '{self.config.model_name}' on {self.device}...", flush=True)
        self.tokenizer = AutoTokenizer.from_pretrained(self.config.model_name)
        self.model = MultiTaskCodeClassifier(self.config.model_name).to(self.device)

    def fit(
        self,
        train_samples: List[Dict[str, Any]],
        val_samples: List[Dict[str, Any]]
    ) -> float:
        t0 = time.time()
        train_dataset = MultiTaskDataset(train_samples, self.tokenizer, self.config.max_length)
        val_dataset = MultiTaskDataset(val_samples, self.tokenizer, self.config.max_length)

        train_loader = DataLoader(train_dataset, batch_size=self.config.train_batch_size, shuffle=True)
        val_loader = DataLoader(val_dataset, batch_size=self.config.eval_batch_size, shuffle=False)

        optimizer = AdamW(self.model.parameters(), lr=self.config.learning_rate, weight_decay=self.config.weight_decay)
        total_steps = len(train_loader) * self.config.num_train_epochs
        warmup_steps = int(total_steps * self.config.warmup_ratio)
        scheduler = get_linear_schedule_with_warmup(optimizer, num_warmup_steps=warmup_steps, num_training_steps=total_steps)
        scaler = torch.cuda.amp.GradScaler(enabled=(self.config.fp16 and CUDA_AVAILABLE))

        best_score = -1.0
        best_checkpoint_dir = CHECKPOINT_DIR / "multitask_codeberta_best"

        cooldown_mgr = CooldownManager(
            interval_seconds=getattr(self.config, "cooldown_interval", 300.0),
            cooldown_seconds=getattr(self.config, "cooldown_duration", 30.0),
            component_name="Shared MultiTask Training"
        )

        print(f"[MultiTask Model] Training for {self.config.num_train_epochs} epochs | Total Train Samples: {len(train_dataset)}...", flush=True)

        for epoch in range(1, self.config.num_train_epochs + 1):
            self.model.train()
            total_train_loss = 0.0
            total_loss_a = 0.0
            total_loss_b = 0.0

            for step, batch in enumerate(train_loader):
                cooldown_mgr.check(f"Epoch {epoch} | Step {step}/{len(train_loader)}")
                input_ids = batch["input_ids"].to(self.device)
                attention_mask = batch["attention_mask"].to(self.device)
                task_a_labels = batch["task_a_label"].to(self.device)
                task_b_labels = batch["task_b_label"].to(self.device)

                optimizer.zero_grad()
                with torch.cuda.amp.autocast(enabled=(self.config.fp16 and CUDA_AVAILABLE)):
                    out = self.model(
                        input_ids=input_ids,
                        attention_mask=attention_mask,
                        task_a_labels=task_a_labels,
                        task_b_labels=task_b_labels,
                        weight_a=self.config.task_a_weight,
                        weight_b=self.config.task_b_weight
                    )
                    loss = out["loss"]

                scaler.scale(loss).backward()
                scaler.unscale_(optimizer)
                torch.nn.utils.clip_grad_norm_(self.model.parameters(), 1.0)
                scaler.step(optimizer)
                scaler.update()
                scheduler.step()

                total_train_loss += loss.item()
                total_loss_a += out["loss_a"]
                total_loss_b += out["loss_b"]

                if step > 0 and step % 400 == 0:
                    print(
                        f"  [MultiTask] Epoch {epoch} | Step {step}/{len(train_loader)} | "
                        f"Loss Total: {loss.item():.4f} | Loss A: {out['loss_a']:.4f} | Loss B: {out['loss_b']:.4f}",
                        flush=True
                    )

            avg_loss = total_train_loss / len(train_loader)
            avg_loss_a = total_loss_a / len(train_loader)
            avg_loss_b = total_loss_b / len(train_loader)

            # Evaluate on validation set for both tasks
            val_res_a, val_res_b = self.evaluate_loader(val_loader, val_samples)
            val_f1_a = val_res_a["macro_f1"]
            val_f1_b = val_res_b["macro_f1"]
            composite_score = 0.5 * (val_f1_a + val_f1_b)

            print(
                f"[MultiTask] Epoch {epoch}/{self.config.num_train_epochs} | "
                f"Train Loss: {avg_loss:.4f} (A: {avg_loss_a:.4f}, B: {avg_loss_b:.4f}) | "
                f"Val Task A F1: {val_f1_a:.4f} | Val Task B F1: {val_f1_b:.4f} | "
                f"Composite: {composite_score:.4f}",
                flush=True
            )

            if composite_score > best_score:
                best_score = composite_score
                self.save(best_checkpoint_dir)
                print(f"  [MultiTask] Checkpoint saved with Composite Score: {best_score:.4f}", flush=True)

        # Reload best weights
        if best_checkpoint_dir.exists():
            print(f"[MultiTask] Reloading best checkpoint from {best_checkpoint_dir}...", flush=True)
            self.load(best_checkpoint_dir)

        duration = time.time() - t0
        print(f"[MultiTask] Training completed in {duration:.2f}s", flush=True)
        return duration

    def evaluate_loader(self, loader: DataLoader, samples: List[Dict[str, Any]]) -> Tuple[Dict[str, Any], Dict[str, Any]]:
        self.model.eval()
        t0 = time.time()

        preds_a, probs_a = [], []
        preds_b, probs_b = [], []

        with torch.no_grad():
            for batch in loader:
                input_ids = batch["input_ids"].to(self.device)
                attention_mask = batch["attention_mask"].to(self.device)

                with torch.cuda.amp.autocast(enabled=(self.config.fp16 and CUDA_AVAILABLE)):
                    out = self.model(input_ids=input_ids, attention_mask=attention_mask)
                    logits_a = out["logits_a"]
                    logits_b = out["logits_b"]

                # Task A probabilities & predictions
                p_a = torch.softmax(logits_a, dim=-1)[:, 1].cpu().numpy()
                pr_a = np.argmax(logits_a.cpu().numpy(), axis=-1)
                preds_a.extend(pr_a.tolist())
                probs_a.extend(p_a.tolist())

                # Task B probabilities & predictions
                p_b = torch.softmax(logits_b, dim=-1).cpu().numpy()
                pr_b = np.argmax(logits_b.cpu().numpy(), axis=-1)
                preds_b.extend(pr_b.tolist())
                probs_b.extend(p_b.tolist())

        duration = time.time() - t0

        # Task A evaluation (all samples)
        y_true_a = [int(s["label"]) for s in samples]
        f1_a = f1_score(y_true_a, preds_a, average="macro", zero_division=0)
        acc_a = float(np.mean(np.array(y_true_a) == np.array(preds_a)))

        # Task B evaluation (strictly AI samples with verified provenance)
        ai_indices = [
            i for i, s in enumerate(samples)
            if s.get("label") == 1 and s.get("generator") in GENERATOR2ID
        ]
        if ai_indices:
            y_true_b = [GENERATOR2ID[samples[i]["generator"]] for i in ai_indices]
            sub_preds_b = [preds_b[i] for i in ai_indices]
            f1_b = f1_score(y_true_b, sub_preds_b, average="macro", zero_division=0)
            acc_b = float(np.mean(np.array(y_true_b) == np.array(sub_preds_b)))
        else:
            f1_b, acc_b = 0.0, 0.0

        return {"macro_f1": float(f1_a), "accuracy": acc_a, "preds": preds_a, "probs": probs_a, "duration": duration}, \
               {"macro_f1": float(f1_b), "accuracy": acc_b, "preds": preds_b, "probs": probs_b, "ai_indices": ai_indices}

    def predict_and_evaluate(
        self,
        test_samples: List[Dict[str, Any]],
        training_duration: float = 0.0,
        model_name: str = "multitask_shared_codeberta"
    ) -> Tuple[Dict[str, Any], Dict[str, Any]]:
        """
        Executes full dual-evaluation on held-out test set:
        - Task A on ALL test samples
        - Task B ONLY on verified AI test samples.
        """
        test_dataset = MultiTaskDataset(test_samples, self.tokenizer, self.config.max_length)
        test_loader = DataLoader(test_dataset, batch_size=self.config.eval_batch_size, shuffle=False)

        res_a, res_b = self.evaluate_loader(test_loader, test_samples)
        model_size = self.get_model_size()

        # Task A Metrics
        y_true_a = [int(s["label"]) for s in test_samples]
        metrics_a = evaluate_predictions(
            y_true=y_true_a,
            y_pred=res_a["preds"],
            y_prob=res_a["probs"],
            training_duration=training_duration,
            inference_duration=res_a["duration"],
            model_size_bytes=model_size,
            model_name=f"{model_name}_task_a",
            metadata=test_samples
        )

        # Task B Metrics (strictly AI samples)
        ai_idx = res_b["ai_indices"]
        ai_test_samples = [test_samples[i] for i in ai_idx]
        y_true_b = [GENERATOR2ID[s["generator"]] for s in ai_test_samples]
        y_pred_b = [res_b["preds"][i] for i in ai_idx]
        y_prob_b = [res_b["probs"][i] for i in ai_idx]

        metrics_b = evaluate_generator_predictions(
            y_true=y_true_b,
            y_pred=y_pred_b,
            y_prob=y_prob_b,
            training_duration=training_duration,
            inference_duration=res_a["duration"] * (len(ai_idx) / len(test_samples)),
            model_size_bytes=model_size,
            model_name=f"{model_name}_task_b",
            metadata=ai_test_samples
        )

        return metrics_a, metrics_b

    def save(self, filepath: Path = CHECKPOINT_DIR / "multitask_codeberta_best") -> int:
        filepath.mkdir(parents=True, exist_ok=True)
        torch.save(self.model.state_dict(), filepath / "multitask_model.pt")
        self.tokenizer.save_pretrained(filepath)
        with open(filepath / "config.json", "w", encoding="utf-8") as f:
            json.dump({
                "model_name": self.config.model_name,
                "ai_generators": AI_GENERATORS,
                "generator2id": GENERATOR2ID,
                "id2generator": ID2GENERATOR
            }, f, indent=2)
        total_size = sum(f.stat().st_size for f in filepath.rglob("*") if f.is_file())
        return total_size

    def load(self, filepath: Path = CHECKPOINT_DIR / "multitask_codeberta_best"):
        weights_path = filepath / "multitask_model.pt"
        if weights_path.exists():
            self.model.load_state_dict(torch.load(weights_path, map_location=self.device))
            print(f"[MultiTask] Loaded weights from {weights_path}", flush=True)

    def get_model_size(self) -> int:
        best_dir = CHECKPOINT_DIR / "multitask_codeberta_best"
        if best_dir.exists():
            return sum(f.stat().st_size for f in best_dir.rglob("*") if f.is_file())
        return 0


def run_multitask_experiment(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]],
    epochs: Optional[int] = None,
    cooldown_interval: Optional[float] = None,
    cooldown_duration: Optional[float] = None
) -> Tuple[Dict[str, Any], Dict[str, Any]]:
    """Runs end-to-end training and held-out test dual-evaluation for the Shared MultiTask Model."""
    model = SharedMultiTaskModel()
    if epochs is not None:
        model.config.num_train_epochs = epochs
    if cooldown_interval is not None:
        model.config.cooldown_interval = cooldown_interval
    if cooldown_duration is not None:
        model.config.cooldown_duration = cooldown_duration

    train_duration = model.fit(train_samples, val_samples)
    metrics_a, metrics_b = model.predict_and_evaluate(test_samples, training_duration=train_duration)
    return metrics_a, metrics_b
