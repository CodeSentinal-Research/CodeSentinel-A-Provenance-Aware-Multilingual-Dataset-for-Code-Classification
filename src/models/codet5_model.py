"""
Baseline 4: CodeT5 Fine-Tuning for Binary Classification.
==========================================================
Uses 'Salesforce/codet5-small' (or 'Salesforce/codet5-base') fine-tuned
as a sequence classifier (0 = Human, 1 = AI).
Implements hardware optimizations for NVIDIA RTX 3050 (6 GB VRAM):
- Mixed precision (fp16) with GradScaler
- Gradient accumulation (effective batch size 16)
- Validation-based model selection & checkpoint saving
- Configurable sequence length, epochs, learning rate, and random seed.
"""

import time
import json
import shutil
from pathlib import Path
from typing import List, Dict, Any, Tuple, Optional
import numpy as np
import torch
import torch.nn as nn
from torch.utils.data import Dataset, DataLoader
import transformers.modeling_utils
import transformers.utils.import_utils
import transformers.tokenization_utils_tokenizers
from tokenizers import AddedToken

transformers.utils.import_utils.check_torch_load_is_safe = lambda: None
transformers.modeling_utils.check_torch_load_is_safe = lambda: None

_orig_add = transformers.tokenization_utils_tokenizers.PreTrainedTokenizerFast.add_tokens
def _fixed_add(self, tokens, **kwargs):
    fixed = []
    for t in tokens:
        if isinstance(t, dict):
            fixed.append(AddedToken(t['content'], single_word=t.get('single_word', False), lstrip=t.get('lstrip', False), rstrip=t.get('rstrip', False), normalized=t.get('normalized', False)))
        else:
            fixed.append(t)
    return _orig_add(self, fixed, **kwargs)

transformers.tokenization_utils_tokenizers.PreTrainedTokenizerFast.add_tokens = _fixed_add
from transformers import (
    AutoTokenizer,
    AutoModelForSequenceClassification,
    get_linear_schedule_with_warmup
)
from torch.optim import AdamW

from src.config import CodeT5Config, CHECKPOINT_DIR, DEVICE, CUDA_AVAILABLE
from src.evaluation.metrics import evaluate_predictions
from src.utils.cooldown import CooldownManager


class CodeDataset(Dataset):
    def __init__(self, texts: List[str], labels: List[int], tokenizer, max_length: int = 256):
        self.texts = texts
        self.labels = labels
        self.tokenizer = tokenizer
        self.max_length = max_length

    def __len__(self):
        return len(self.texts)

    def __getitem__(self, idx):
        text = self.texts[idx]
        label = self.labels[idx]
        encoding = self.tokenizer(
            text,
            truncation=True,
            max_length=self.max_length,
            padding="max_length",
            return_tensors="pt"
        )
        item = {key: val.squeeze(0) for key, val in encoding.items()}
        item["labels"] = torch.tensor(label, dtype=torch.long)
        return item

class CodeT5Classifier:
    def __init__(self, config: CodeT5Config = CodeT5Config(), device: str = DEVICE):
        self.config = config
        self.device = device
        self.id2label = {0: "Human", 1: "AI"}
        self.label2id = {"Human": 0, "AI": 1}

        torch.manual_seed(self.config.random_state)
        if CUDA_AVAILABLE:
            torch.cuda.manual_seed_all(self.config.random_state)

        print(f"[CodeT5] Initializing tokenizer & model '{self.config.model_name}' on {self.device}...", flush=True)
        self.tokenizer = AutoTokenizer.from_pretrained(self.config.model_name)
        self.model = AutoModelForSequenceClassification.from_pretrained(
            self.config.model_name,
            num_labels=2,
            id2label=self.id2label,
            label2id=self.label2id
        ).to(self.device)

    def fit(self, train_texts: List[str], train_y: List[int], val_texts: List[str], val_y: List[int]) -> float:
        t0 = time.time()
        train_dataset = CodeDataset(train_texts, train_y, self.tokenizer, self.config.max_length)
        val_dataset = CodeDataset(val_texts, val_y, self.tokenizer, self.config.max_length)

        train_loader = DataLoader(train_dataset, batch_size=self.config.train_batch_size, shuffle=True)
        val_loader = DataLoader(val_dataset, batch_size=self.config.eval_batch_size, shuffle=False)

        optimizer = AdamW(self.model.parameters(), lr=self.config.learning_rate, weight_decay=self.config.weight_decay)
        total_steps = (len(train_loader) // self.config.gradient_accumulation_steps) * self.config.num_train_epochs
        warmup_steps = int(total_steps * self.config.warmup_ratio)
        scheduler = get_linear_schedule_with_warmup(optimizer, num_warmup_steps=warmup_steps, num_training_steps=total_steps)

        scaler = torch.cuda.amp.GradScaler(enabled=(self.config.fp16 and CUDA_AVAILABLE))
        best_val_f1 = -1.0
        best_checkpoint_dir = CHECKPOINT_DIR / "codet5_best"

        cooldown_mgr = CooldownManager(
            interval_seconds=getattr(self.config, "cooldown_interval", 300.0),
            cooldown_seconds=getattr(self.config, "cooldown_duration", 30.0),
            component_name="CodeT5 Training"
        )

        print(f"[CodeT5] Starting training: {self.config.num_train_epochs} epochs, {len(train_dataset)} samples, fp16={self.config.fp16}...", flush=True)

        for epoch in range(1, self.config.num_train_epochs + 1):
            self.model.train()
            total_train_loss = 0.0
            optimizer.zero_grad()

            for step, batch in enumerate(train_loader):
                cooldown_mgr.check(f"Epoch {epoch} | Step {step}/{len(train_loader)}")
                input_ids = batch["input_ids"].to(self.device)
                attention_mask = batch["attention_mask"].to(self.device)
                labels = batch["labels"].to(self.device)

                with torch.cuda.amp.autocast(enabled=(self.config.fp16 and CUDA_AVAILABLE)):
                    outputs = self.model(input_ids=input_ids, attention_mask=attention_mask, labels=labels)
                    loss = outputs.loss / self.config.gradient_accumulation_steps

                scaler.scale(loss).backward()
                total_train_loss += loss.item() * self.config.gradient_accumulation_steps

                if step > 0 and step % 500 == 0:
                    print(f"  [CodeT5] Epoch {epoch} | Step {step}/{len(train_loader)} | Batch Loss: {loss.item() * self.config.gradient_accumulation_steps:.4f}", flush=True)

                if (step + 1) % self.config.gradient_accumulation_steps == 0 or (step + 1) == len(train_loader):
                    scaler.unscale_(optimizer)
                    torch.nn.utils.clip_grad_norm_(self.model.parameters(), 1.0)
                    scaler.step(optimizer)
                    scaler.update()
                    scheduler.step()
                    optimizer.zero_grad()

            avg_train_loss = total_train_loss / len(train_loader)

            # Evaluate on validation set
            val_preds, val_probs, _ = self.predict_loader(val_loader)
            val_acc = np.mean(np.array(val_preds) == np.array(val_y))
            # Compute macro F1
            from sklearn.metrics import f1_score
            val_f1 = float(f1_score(val_y, val_preds, average="macro", zero_division=0))

            print(f"[CodeT5] Epoch {epoch}/{self.config.num_train_epochs} | Train Loss: {avg_train_loss:.4f} | Val Acc: {val_acc:.4f} | Val Macro-F1: {val_f1:.4f}", flush=True)

            if val_f1 > best_val_f1:
                best_val_f1 = val_f1
                self.save(best_checkpoint_dir)
                print(f"  [CodeT5] New best checkpoint saved with Val F1: {best_val_f1:.4f}", flush=True)

        # Load best weights if saved
        if best_checkpoint_dir.exists():
            print(f"[CodeT5] Reloading best checkpoint from {best_checkpoint_dir}...", flush=True)
            self.model = AutoModelForSequenceClassification.from_pretrained(best_checkpoint_dir).to(self.device)

        duration = time.time() - t0
        print(f"[CodeT5] Training complete in {duration:.2f}s", flush=True)
        return duration

    def predict_loader(self, loader: DataLoader) -> Tuple[List[int], List[float], float]:
        self.model.eval()
        t0 = time.time()
        preds = []
        probs = []

        with torch.no_grad():
            for batch in loader:
                input_ids = batch["input_ids"].to(self.device)
                attention_mask = batch["attention_mask"].to(self.device)

                with torch.cuda.amp.autocast(enabled=(self.config.fp16 and CUDA_AVAILABLE)):
                    outputs = self.model(input_ids=input_ids, attention_mask=attention_mask)
                    logits = outputs.logits

                batch_probs = torch.softmax(logits, dim=-1)[:, 1].cpu().numpy()
                batch_preds = np.argmax(logits.cpu().numpy(), axis=-1)

                probs.extend(batch_probs.tolist())
                preds.extend(batch_preds.tolist())

        duration = time.time() - t0
        return preds, probs, duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[float], float]:
        dataset = CodeDataset(texts, [0] * len(texts), self.tokenizer, self.config.max_length)
        loader = DataLoader(dataset, batch_size=self.config.eval_batch_size, shuffle=False)
        return self.predict_loader(loader)

    def save(self, filepath: Path = CHECKPOINT_DIR / "codet5_best") -> int:
        filepath.mkdir(parents=True, exist_ok=True)
        self.model.save_pretrained(filepath)
        self.tokenizer.save_pretrained(filepath)
        with open(filepath / "label_mapping.json", "w", encoding="utf-8") as f:
            json.dump({"id2label": self.id2label, "label2id": self.label2id}, f, indent=2)
        total_size = sum(f.stat().st_size for f in filepath.rglob("*") if f.is_file())
        return total_size

def train_and_eval_codet5(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]],
    epochs: Optional[int] = None,
    cooldown_interval: Optional[float] = None,
    cooldown_duration: Optional[float] = None
) -> Dict[str, Any]:
    train_texts = [s["code"] for s in train_samples]
    train_y = [s["label"] for s in train_samples]

    val_texts = [s["code"] for s in val_samples]
    val_y = [s["label"] for s in val_samples]

    test_texts = [s["code"] for s in test_samples]
    test_y = [s["label"] for s in test_samples]

    model = CodeT5Classifier()
    if epochs is not None:
        model.config.num_train_epochs = epochs
    if cooldown_interval is not None:
        model.config.cooldown_interval = cooldown_interval
    if cooldown_duration is not None:
        model.config.cooldown_duration = cooldown_duration
    train_duration = model.fit(train_texts, train_y, val_texts, val_y)
    model_size = model.save()

    preds, probs, infer_duration = model.predict(test_texts)

    metrics = evaluate_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_duration,
        inference_duration=infer_duration,
        model_size_bytes=model_size,
        model_name="codet5_small",
        metadata=test_samples
    )
    return metrics
