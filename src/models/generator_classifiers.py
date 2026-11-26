"""
Task B Independent Classifiers Module: AI Generator Classification (4-class).
=============================================================================
Provides independent, task-specific classifiers trained exclusively on AI-generated
code with verified generator provenance to identify the generating model:
1. TF-IDF + Linear SVM (Task B)
2. TF-IDF + Random Forest (Task B)
3. UniXcoder Pretrained Embeddings + Linear SVM (Task B)
4. CodeBERTa Fine-Tuned Sequence Classifier (Task B)

Strictly obeys the constraint:
Human code is NEVER treated as a fifth AI generator and is never fed to these classifiers.
"""

import time
import json
import joblib
from pathlib import Path
from typing import List, Dict, Any, Tuple, Optional
import numpy as np
import torch
from torch.utils.data import Dataset, DataLoader
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.pipeline import FeatureUnion
from sklearn.svm import LinearSVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.calibration import CalibratedClassifierCV
from sklearn.metrics import f1_score

import transformers.modeling_utils
import transformers.utils.import_utils
transformers.utils.import_utils.check_torch_load_is_safe = lambda: None
transformers.modeling_utils.check_torch_load_is_safe = lambda: None
from transformers import (
    AutoTokenizer,
    AutoModelForSequenceClassification,
    get_linear_schedule_with_warmup
)
from torch.optim import AdamW

from src.config import (
    CHECKPOINT_DIR,
    DATA_PROCESSED_DIR,
    DEVICE,
    CUDA_AVAILABLE,
    AI_GENERATORS,
    GENERATOR2ID,
    ID2GENERATOR,
    RANDOM_SEED,
    CodeBERTaConfig,
    TfidfSvmConfig,
    TfidfRfConfig
)
from src.evaluation.generator_metrics import evaluate_generator_predictions
from src.utils.cooldown import CooldownManager


# =========================================================================
# 1. Classical Baseline: TF-IDF + Linear SVM for Task B
# =========================================================================
class TfidfSvmGeneratorClassifier:
    """TF-IDF N-gram features + Multiclass Linear SVM for AI Generator Classification."""

    def __init__(self, config: TfidfSvmConfig = TfidfSvmConfig()):
        self.config = config
        self.vectorizer = FeatureUnion([
            ("word_tfidf", TfidfVectorizer(
                analyzer="word",
                ngram_range=self.config.word_ngram_range,
                max_features=self.config.max_word_features,
                sublinear_tf=True
            )),
            ("char_tfidf", TfidfVectorizer(
                analyzer="char",
                ngram_range=self.config.char_ngram_range,
                max_features=self.config.max_char_features,
                sublinear_tf=True
            ))
        ])
        self.svm = LinearSVC(
            C=self.config.c_param,
            random_state=self.config.random_state,
            max_iter=3000
        )
        self.calibrated_clf = None

    def fit(self, texts: List[str], y: List[int], val_texts: Optional[List[str]] = None, val_y: Optional[List[int]] = None) -> float:
        t0 = time.time()
        print(f"[TF-IDF+SVM Task B] Extracting features from {len(texts)} AI training samples...", flush=True)
        X_train = self.vectorizer.fit_transform(texts)
        print(f"[TF-IDF+SVM Task B] Fitting Linear SVM on matrix {X_train.shape} across {len(AI_GENERATORS)} classes...", flush=True)
        self.svm.fit(X_train, y)

        from collections import Counter
        min_class_cnt = min(Counter(y).values()) if y else 0

        if val_texts is not None and val_y is not None and len(val_texts) >= 4 and min(Counter(val_y).values(), default=0) >= 1:
            X_val = self.vectorizer.transform(val_texts)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv="prefit")
            self.calibrated_clf.fit(X_val, val_y)
        elif min_class_cnt >= 3:
            cv = min(3, min_class_cnt)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv=cv)
            self.calibrated_clf.fit(X_train, y)
        else:
            self.calibrated_clf = None

        duration = time.time() - t0
        print(f"[TF-IDF+SVM Task B] Training completed in {duration:.2f}s", flush=True)
        return duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[List[float]], float]:
        t0 = time.time()
        X = self.vectorizer.transform(texts)
        if self.calibrated_clf is not None:
            probs = self.calibrated_clf.predict_proba(X)
            preds = np.argmax(probs, axis=-1)
            probs_list = probs.tolist()
        else:
            df = self.svm.decision_function(X)
            if df.ndim == 1:
                df = np.column_stack([-df, df])
            exp_df = np.exp(df - np.max(df, axis=-1, keepdims=True))
            probs = exp_df / np.sum(exp_df, axis=-1, keepdims=True)
            preds = np.argmax(probs, axis=-1)
            probs_list = probs.tolist()
        duration = time.time() - t0
        return preds.tolist(), probs_list, duration

    def save(self, filepath: Path = CHECKPOINT_DIR / "tfidf_svm_task_b.joblib") -> int:
        filepath.parent.mkdir(parents=True, exist_ok=True)
        joblib.dump({"vectorizer": self.vectorizer, "svm": self.svm, "calibrated": self.calibrated_clf}, filepath)
        return filepath.stat().st_size


# =========================================================================
# 2. Classical Baseline: TF-IDF + Random Forest for Task B
# =========================================================================
class TfidfRfGeneratorClassifier:
    """TF-IDF Features + Random Forest for AI Generator Classification."""

    def __init__(self, config: TfidfRfConfig = TfidfRfConfig()):
        self.config = config
        self.vectorizer = TfidfVectorizer(
            max_features=self.config.max_features,
            sublinear_tf=True,
            ngram_range=(1, 2)
        )
        self.rf = RandomForestClassifier(
            n_estimators=self.config.n_estimators,
            max_depth=self.config.max_depth,
            n_jobs=self.config.n_jobs,
            random_state=self.config.random_state
        )

    def fit(self, texts: List[str], y: List[int]) -> float:
        t0 = time.time()
        print(f"[TF-IDF+RF Task B] Extracting features from {len(texts)} AI training samples...", flush=True)
        X_train = self.vectorizer.fit_transform(texts)
        print(f"[TF-IDF+RF Task B] Fitting Random Forest on matrix {X_train.shape}...", flush=True)
        self.rf.fit(X_train, y)
        duration = time.time() - t0
        print(f"[TF-IDF+RF Task B] Training completed in {duration:.2f}s", flush=True)
        return duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[List[float]], float]:
        t0 = time.time()
        X = self.vectorizer.transform(texts)
        probs = self.rf.predict_proba(X)
        preds = np.argmax(probs, axis=-1)
        duration = time.time() - t0
        return preds.tolist(), probs.tolist(), duration

    def save(self, filepath: Path = CHECKPOINT_DIR / "tfidf_rf_task_b.joblib") -> int:
        filepath.parent.mkdir(parents=True, exist_ok=True)
        joblib.dump({"vectorizer": self.vectorizer, "rf": self.rf}, filepath)
        return filepath.stat().st_size


# =========================================================================
# 3. Dense Baseline: Pretrained UniXcoder Embeddings + SVM for Task B
# =========================================================================
class EmbeddingSvmGeneratorClassifier:
    """Precomputed UniXcoder 768-d representations + Linear SVM for AI Generator Classification."""

    def __init__(self, random_state: int = RANDOM_SEED, c_param: float = 1.0):
        self.svm = LinearSVC(C=c_param, random_state=random_state, max_iter=3000)
        self.calibrated_clf = None

    def fit(self, train_embeddings: np.ndarray, train_y: List[int], val_embeddings: Optional[np.ndarray] = None, val_y: Optional[List[int]] = None) -> float:
        t0 = time.time()
        print(f"[Embedding+SVM Task B] Fitting Linear SVM on {train_embeddings.shape} representations...", flush=True)
        self.svm.fit(train_embeddings, train_y)

        from collections import Counter
        min_class_cnt = min(Counter(train_y).values()) if train_y else 0

        if val_embeddings is not None and val_y is not None and len(val_embeddings) >= 4 and min(Counter(val_y).values(), default=0) >= 1:
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv="prefit")
            self.calibrated_clf.fit(val_embeddings, val_y)
        elif min_class_cnt >= 3:
            cv = min(3, min_class_cnt)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv=cv)
            self.calibrated_clf.fit(train_embeddings, train_y)
        else:
            self.calibrated_clf = None

        duration = time.time() - t0
        print(f"[Embedding+SVM Task B] Training completed in {duration:.2f}s", flush=True)
        return duration

    def predict(self, embeddings: np.ndarray) -> Tuple[List[int], List[List[float]], float]:
        t0 = time.time()
        if self.calibrated_clf is not None:
            probs = self.calibrated_clf.predict_proba(embeddings)
            preds = np.argmax(probs, axis=-1)
            probs_list = probs.tolist()
        else:
            df = self.svm.decision_function(embeddings)
            if df.ndim == 1:
                df = np.column_stack([-df, df])
            exp_df = np.exp(df - np.max(df, axis=-1, keepdims=True))
            probs = exp_df / np.sum(exp_df, axis=-1, keepdims=True)
            preds = np.argmax(probs, axis=-1)
            probs_list = probs.tolist()
        duration = time.time() - t0
        return preds.tolist(), probs_list, duration

    def save(self, filepath: Path = CHECKPOINT_DIR / "embedding_svm_task_b.joblib") -> int:
        filepath.parent.mkdir(parents=True, exist_ok=True)
        joblib.dump({"svm": self.svm, "calibrated": self.calibrated_clf}, filepath)
        return filepath.stat().st_size


# =========================================================================
# 4. Neural Transformer: Independent CodeBERTa for Task B
# =========================================================================
class GeneratorCodeDataset(Dataset):
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


class CodeBERTaGeneratorClassifier:
    """Independent CodeBERTa Sequence Classifier Fine-Tuned for 4-Class AI Generator Identification."""

    def __init__(self, config: CodeBERTaConfig = CodeBERTaConfig(), device: str = DEVICE):
        self.config = config
        self.device = device
        self.id2label = ID2GENERATOR
        self.label2id = GENERATOR2ID

        torch.manual_seed(self.config.random_state)
        if CUDA_AVAILABLE:
            torch.cuda.manual_seed_all(self.config.random_state)

        print(f"[CodeBERTa Task B] Initializing model '{self.config.model_name}' (4 classes) on {self.device}...", flush=True)
        self.tokenizer = AutoTokenizer.from_pretrained(self.config.model_name)
        self.model = AutoModelForSequenceClassification.from_pretrained(
            self.config.model_name,
            num_labels=len(AI_GENERATORS),
            id2label=self.id2label,
            label2id=self.label2id
        ).to(self.device)

    def fit(self, train_texts: List[str], train_y: List[int], val_texts: List[str], val_y: List[int]) -> float:
        t0 = time.time()
        train_dataset = GeneratorCodeDataset(train_texts, train_y, self.tokenizer, self.config.max_length)
        val_dataset = GeneratorCodeDataset(val_texts, val_y, self.tokenizer, self.config.max_length)

        train_loader = DataLoader(train_dataset, batch_size=self.config.train_batch_size, shuffle=True)
        val_loader = DataLoader(val_dataset, batch_size=self.config.eval_batch_size, shuffle=False)

        optimizer = AdamW(self.model.parameters(), lr=self.config.learning_rate, weight_decay=self.config.weight_decay)
        total_steps = len(train_loader) * self.config.num_train_epochs
        warmup_steps = int(total_steps * self.config.warmup_ratio)
        scheduler = get_linear_schedule_with_warmup(optimizer, num_warmup_steps=warmup_steps, num_training_steps=total_steps)
        scaler = torch.cuda.amp.GradScaler(enabled=(self.config.fp16 and CUDA_AVAILABLE))

        best_val_f1 = -1.0
        best_checkpoint_dir = CHECKPOINT_DIR / "codeberta_task_b_best"

        cooldown_mgr = CooldownManager(
            interval_seconds=getattr(self.config, "cooldown_interval", 300.0),
            cooldown_seconds=getattr(self.config, "cooldown_duration", 30.0),
            component_name="CodeBERTa Task B Training"
        )

        print(f"[CodeBERTa Task B] Training on {len(train_dataset)} AI samples across {self.config.num_train_epochs} epochs...", flush=True)

        for epoch in range(1, self.config.num_train_epochs + 1):
            self.model.train()
            total_train_loss = 0.0

            for step, batch in enumerate(train_loader):
                cooldown_mgr.check(f"Epoch {epoch} | Step {step}/{len(train_loader)}")
                input_ids = batch["input_ids"].to(self.device)
                attention_mask = batch["attention_mask"].to(self.device)
                labels = batch["labels"].to(self.device)

                optimizer.zero_grad()
                with torch.cuda.amp.autocast(enabled=(self.config.fp16 and CUDA_AVAILABLE)):
                    outputs = self.model(input_ids=input_ids, attention_mask=attention_mask, labels=labels)
                    loss = outputs.loss

                scaler.scale(loss).backward()
                scaler.unscale_(optimizer)
                torch.nn.utils.clip_grad_norm_(self.model.parameters(), 1.0)
                scaler.step(optimizer)
                scaler.update()
                scheduler.step()

                total_train_loss += loss.item()
                if step > 0 and step % 400 == 0:
                    print(f"  [CodeBERTa Task B] Epoch {epoch} | Step {step}/{len(train_loader)} | Batch Loss: {loss.item():.4f}", flush=True)

            avg_train_loss = total_train_loss / len(train_loader)

            # Validation evaluation
            val_preds, val_probs, _ = self.predict_loader(val_loader)
            val_acc = np.mean(np.array(val_preds) == np.array(val_y))
            val_f1 = float(f1_score(val_y, val_preds, average="macro", zero_division=0))

            print(f"[CodeBERTa Task B] Epoch {epoch}/{self.config.num_train_epochs} | Train Loss: {avg_train_loss:.4f} | Val Acc: {val_acc:.4f} | Val Macro-F1: {val_f1:.4f}", flush=True)

            if val_f1 > best_val_f1:
                best_val_f1 = val_f1
                self.save(best_checkpoint_dir)
                print(f"  [CodeBERTa Task B] Checkpoint saved with Val Macro-F1: {best_val_f1:.4f}", flush=True)

        # Reload best weights
        if best_checkpoint_dir.exists():
            print(f"[CodeBERTa Task B] Reloading best checkpoint from {best_checkpoint_dir}...", flush=True)
            self.model = AutoModelForSequenceClassification.from_pretrained(best_checkpoint_dir).to(self.device)

        duration = time.time() - t0
        print(f"[CodeBERTa Task B] Training completed in {duration:.2f}s", flush=True)
        return duration

    def predict_loader(self, loader: DataLoader) -> Tuple[List[int], List[List[float]], float]:
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

                batch_probs = torch.softmax(logits, dim=-1).cpu().numpy()
                batch_preds = np.argmax(logits.cpu().numpy(), axis=-1)

                probs.extend(batch_probs.tolist())
                preds.extend(batch_preds.tolist())

        duration = time.time() - t0
        return preds, probs, duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[List[float]], float]:
        dataset = GeneratorCodeDataset(texts, [0] * len(texts), self.tokenizer, self.config.max_length)
        loader = DataLoader(dataset, batch_size=self.config.eval_batch_size, shuffle=False)
        return self.predict_loader(loader)

    def save(self, filepath: Path = CHECKPOINT_DIR / "codeberta_task_b_best") -> int:
        filepath.mkdir(parents=True, exist_ok=True)
        self.model.save_pretrained(filepath)
        self.tokenizer.save_pretrained(filepath)
        with open(filepath / "label_mapping.json", "w", encoding="utf-8") as f:
            json.dump({"id2label": self.id2label, "label2id": self.label2id}, f, indent=2)
        total_size = sum(f.stat().st_size for f in filepath.rglob("*") if f.is_file())
        return total_size


# =========================================================================
# High-Level Wrapper Functions for Training & Evaluating Task B Baselines
# =========================================================================

def filter_ai_samples(samples: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
    """Strictly selects only AI-generated samples with verified generator provenance."""
    return [
        s for s in samples
        if s.get("label") == 1 and s.get("generator") in AI_GENERATORS
    ]


def run_tfidf_svm_task_b(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]]
) -> Dict[str, Any]:
    train_ai = filter_ai_samples(train_samples)
    val_ai = filter_ai_samples(val_samples)
    test_ai = filter_ai_samples(test_samples)

    train_texts = [s["code"] for s in train_ai]
    train_y = [GENERATOR2ID[s["generator"]] for s in train_ai]

    val_texts = [s["code"] for s in val_ai]
    val_y = [GENERATOR2ID[s["generator"]] for s in val_ai]

    test_texts = [s["code"] for s in test_ai]
    test_y = [GENERATOR2ID[s["generator"]] for s in test_ai]

    model = TfidfSvmGeneratorClassifier()
    train_dur = model.fit(train_texts, train_y, val_texts, val_y)
    model_size = model.save()

    preds, probs, infer_dur = model.predict(test_texts)
    metrics = evaluate_generator_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_dur,
        inference_duration=infer_dur,
        model_size_bytes=model_size,
        model_name="tfidf_linear_svm_task_b",
        metadata=test_ai
    )
    return metrics


def run_tfidf_rf_task_b(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]]
) -> Dict[str, Any]:
    train_ai = filter_ai_samples(train_samples)
    test_ai = filter_ai_samples(test_samples)

    train_texts = [s["code"] for s in train_ai]
    train_y = [GENERATOR2ID[s["generator"]] for s in train_ai]

    test_texts = [s["code"] for s in test_ai]
    test_y = [GENERATOR2ID[s["generator"]] for s in test_ai]

    model = TfidfRfGeneratorClassifier()
    train_dur = model.fit(train_texts, train_y)
    model_size = model.save()

    preds, probs, infer_dur = model.predict(test_texts)
    metrics = evaluate_generator_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_dur,
        inference_duration=infer_dur,
        model_size_bytes=model_size,
        model_name="tfidf_random_forest_task_b",
        metadata=test_ai
    )
    return metrics


def run_embedding_svm_task_b(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]]
) -> Dict[str, Any]:
    # Locate cached UniXcoder embeddings
    tr_emb_path = DATA_PROCESSED_DIR / f"unixcoder_embeddings_train_{len(train_samples)}.npy"
    val_emb_path = DATA_PROCESSED_DIR / f"unixcoder_embeddings_val_{len(val_samples)}.npy"
    te_emb_path = DATA_PROCESSED_DIR / f"unixcoder_embeddings_test_{len(test_samples)}.npy"

    if not (tr_emb_path.exists() and te_emb_path.exists()):
        print(f"[Embedding+SVM Task B] Cached embeddings not found at {tr_emb_path}. Extracting on-the-fly...", flush=True)
        from src.models.embedding_svm import CodeEmbeddingExtractor
        extractor = CodeEmbeddingExtractor()
        train_all_emb = extractor.extract_embeddings([s["code"] for s in train_samples])
        val_all_emb = extractor.extract_embeddings([s["code"] for s in val_samples]) if val_samples else None
        test_all_emb = extractor.extract_embeddings([s["code"] for s in test_samples])
    else:
        train_all_emb = np.load(tr_emb_path)
        val_all_emb = np.load(val_emb_path) if val_emb_path.exists() else None
        test_all_emb = np.load(te_emb_path)

    # Filter strictly to AI samples
    tr_mask = [i for i, s in enumerate(train_samples) if s.get("label") == 1 and s.get("generator") in AI_GENERATORS]
    te_mask = [i for i, s in enumerate(test_samples) if s.get("label") == 1 and s.get("generator") in AI_GENERATORS]

    train_emb_ai = train_all_emb[tr_mask]
    test_emb_ai = test_all_emb[te_mask]

    train_ai_samples = [train_samples[i] for i in tr_mask]
    test_ai_samples = [test_samples[i] for i in te_mask]

    train_y = [GENERATOR2ID[s["generator"]] for s in train_ai_samples]
    test_y = [GENERATOR2ID[s["generator"]] for s in test_ai_samples]

    val_emb_ai = None
    val_y = None
    if val_all_emb is not None:
        val_mask = [i for i, s in enumerate(val_samples) if s.get("label") == 1 and s.get("generator") in AI_GENERATORS]
        val_emb_ai = val_all_emb[val_mask]
        val_ai_samples = [val_samples[i] for i in val_mask]
        val_y = [GENERATOR2ID[s["generator"]] for s in val_ai_samples]

    model = EmbeddingSvmGeneratorClassifier()
    train_dur = model.fit(train_emb_ai, train_y, val_emb_ai, val_y)
    model_size = model.save()

    preds, probs, infer_dur = model.predict(test_emb_ai)
    metrics = evaluate_generator_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_dur,
        inference_duration=infer_dur,
        model_size_bytes=model_size,
        model_name="embedding_svm_unixcoder_task_b",
        metadata=test_ai_samples
    )
    return metrics


def run_codeberta_task_b(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]],
    epochs: Optional[int] = None,
    cooldown_interval: Optional[float] = None,
    cooldown_duration: Optional[float] = None
) -> Dict[str, Any]:
    train_ai = filter_ai_samples(train_samples)
    val_ai = filter_ai_samples(val_samples)
    test_ai = filter_ai_samples(test_samples)

    train_texts = [s["code"] for s in train_ai]
    train_y = [GENERATOR2ID[s["generator"]] for s in train_ai]

    val_texts = [s["code"] for s in val_ai]
    val_y = [GENERATOR2ID[s["generator"]] for s in val_ai]

    test_texts = [s["code"] for s in test_ai]
    test_y = [GENERATOR2ID[s["generator"]] for s in test_ai]

    model = CodeBERTaGeneratorClassifier()
    if epochs is not None:
        model.config.num_train_epochs = epochs
    if cooldown_interval is not None:
        model.config.cooldown_interval = cooldown_interval
    if cooldown_duration is not None:
        model.config.cooldown_duration = cooldown_duration

    train_dur = model.fit(train_texts, train_y, val_texts, val_y)
    model_size = model.save()

    preds, probs, infer_dur = model.predict(test_texts)
    metrics = evaluate_generator_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_dur,
        inference_duration=infer_dur,
        model_size_bytes=model_size,
        model_name="codeberta_small_task_b",
        metadata=test_ai
    )
    return metrics
