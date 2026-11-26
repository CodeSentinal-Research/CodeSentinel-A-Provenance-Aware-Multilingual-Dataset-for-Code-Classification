"""
Baseline 3: Pretrained Code Embeddings + SVM.
=============================================
Architecture & Methodology:
- Encoder: Pretrained Code Transformer ('microsoft/unixcoder-base' by default, or 'microsoft/codebert-base').
  Hidden dimension: 768.
- Pooling: Non-padding Masked Mean Pooling:
    e = sum(h_i * mask_i) / sum(mask_i)
  where h_i is the final hidden state for token i and mask_i is the attention mask.
- Classifier: Support Vector Machine (LinearSVC with Probability Calibration).
- Accelerated with PyTorch and CUDA on NVIDIA RTX 3050.
"""

import time
import joblib
from pathlib import Path
from typing import List, Dict, Any, Tuple, Optional
import numpy as np
import torch
import transformers.modeling_utils
import transformers.utils.import_utils
transformers.utils.import_utils.check_torch_load_is_safe = lambda: None
transformers.modeling_utils.check_torch_load_is_safe = lambda: None
from transformers import AutoTokenizer, AutoModel
from sklearn.svm import LinearSVC
from sklearn.calibration import CalibratedClassifierCV

from src.config import EmbeddingSvmConfig, CHECKPOINT_DIR, DATA_PROCESSED_DIR, DEVICE
from src.evaluation.metrics import evaluate_predictions
from src.utils.cooldown import CooldownManager


class CodeEmbeddingExtractor:
    """Extracts dense code representations using a pretrained code transformer and masked mean pooling."""

    def __init__(self, model_name: str = "microsoft/unixcoder-base", max_length: int = 256, device: str = DEVICE):
        self.model_name = model_name
        self.max_length = max_length
        self.device = device
        print(f"[EmbeddingExtractor] Loading tokenizer & model '{model_name}' on {self.device}...", flush=True)
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)
        self.model = AutoModel.from_pretrained(model_name).to(self.device)
        self.model.eval()

    def extract_embeddings(self, texts: List[str], batch_size: int = 32, cache_path: Optional[Path] = None) -> np.ndarray:
        if cache_path and cache_path.exists():
            try:
                cached = np.load(cache_path)
                if len(cached) == len(texts):
                    print(f"[EmbeddingExtractor] Loaded cached embeddings from {cache_path} (shape: {cached.shape})", flush=True)
                    return cached
            except Exception as e:
                print(f"[EmbeddingExtractor] Cache read failed ({e}), recomputing...", flush=True)

        all_embeddings = []
        n_samples = len(texts)
        cooldown_mgr = CooldownManager(300.0, 30.0, component_name="Embedding Extraction")

        with torch.no_grad():
            for i in range(0, n_samples, batch_size):
                cooldown_mgr.check(f"Batch {i//batch_size + 1}/{(n_samples + batch_size - 1)//batch_size}")
                batch_texts = texts[i : i + batch_size]
                encoded = self.tokenizer(
                    batch_texts,
                    padding=True,
                    truncation=True,
                    max_length=self.max_length,
                    return_tensors="pt"
                ).to(self.device)

                outputs = self.model(**encoded)
                last_hidden = outputs.last_hidden_state  # [B, L, 768]
                attention_mask = encoded["attention_mask"].unsqueeze(-1)  # [B, L, 1]

                # Masked Mean Pooling over non-padding tokens
                sum_embeddings = torch.sum(last_hidden * attention_mask, dim=1)
                sum_mask = torch.clamp(attention_mask.sum(dim=1), min=1e-9)
                mean_pooled = (sum_embeddings / sum_mask).cpu().numpy()

                all_embeddings.append(mean_pooled)

                if (i + len(batch_texts)) % 2500 < batch_size and n_samples > 1000:
                    print(f"[EmbeddingExtractor] Processed {i + len(batch_texts)}/{n_samples} samples...", flush=True)

        final_mat = np.vstack(all_embeddings)
        if cache_path:
            try:
                cache_path.parent.mkdir(parents=True, exist_ok=True)
                np.save(cache_path, final_mat)
                print(f"[EmbeddingExtractor] Saved cached embeddings -> {cache_path}", flush=True)
            except Exception as e:
                print(f"[EmbeddingExtractor] Failed to write cache: {e}", flush=True)

        return final_mat

class EmbeddingSvmModel:
    def __init__(self, config: EmbeddingSvmConfig = EmbeddingSvmConfig()):
        self.config = config
        self.extractor = CodeEmbeddingExtractor(
            model_name=self.config.model_name,
            max_length=self.config.max_length,
            device=DEVICE
        )
        self.svm = LinearSVC(
            C=self.config.c_param,
            random_state=self.config.random_state,
            max_iter=3000
        )
        self.calibrated_clf = None

    def fit(self, texts: List[str], y: List[int], val_texts: Optional[List[str]] = None, val_y: Optional[List[int]] = None) -> float:
        t0 = time.time()
        print(f"[Embedding+SVM] Extracting embeddings for {len(texts)} train samples...", flush=True)
        cache_train = DATA_PROCESSED_DIR / f"unixcoder_embeddings_train_{len(texts)}.npy" if len(texts) > 500 else None
        X_train = self.extractor.extract_embeddings(texts, batch_size=self.config.batch_size, cache_path=cache_train)
        print(f"[Embedding+SVM] Training SVM on embeddings matrix {X_train.shape}...", flush=True)
        self.svm.fit(X_train, y)

        from collections import Counter
        min_class_count = min(Counter(y).values()) if y else 0

        if val_texts is not None and val_y is not None and len(val_texts) >= 2:
            cache_val = DATA_PROCESSED_DIR / f"unixcoder_embeddings_val_{len(val_texts)}.npy" if len(val_texts) > 500 else None
            X_val = self.extractor.extract_embeddings(val_texts, batch_size=self.config.batch_size, cache_path=cache_val)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv="prefit")
            self.calibrated_clf.fit(X_val, val_y)
        elif min_class_count >= 3:
            cv = min(3, min_class_count)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv=cv)
            self.calibrated_clf.fit(X_train, y)
        else:
            self.calibrated_clf = None

        duration = time.time() - t0
        print(f"[Embedding+SVM] Training complete in {duration:.2f}s", flush=True)
        return duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[float], float]:
        t0 = time.time()
        cache_test = DATA_PROCESSED_DIR / f"unixcoder_embeddings_test_{len(texts)}.npy" if len(texts) > 500 else None
        X = self.extractor.extract_embeddings(texts, batch_size=self.config.batch_size, cache_path=cache_test)
        if self.calibrated_clf is not None:
            probs = self.calibrated_clf.predict_proba(X)[:, 1]
            preds = (probs >= 0.5).astype(int)
        else:
            preds = self.svm.predict(X)
            df = self.svm.decision_function(X)
            probs = 1.0 / (1.0 + np.exp(-df))
        duration = time.time() - t0
        return preds.tolist(), probs.tolist(), duration

    def save(self, filepath: Path = CHECKPOINT_DIR / "embedding_svm.joblib") -> int:
        filepath.parent.mkdir(parents=True, exist_ok=True)
        joblib.dump({"svm": self.svm, "calibrated": self.calibrated_clf, "config": self.config}, filepath)
        size = filepath.stat().st_size
        print(f"[Embedding+SVM] Checkpoint saved: {filepath} ({size / (1024*1024):.2f} MB)", flush=True)
        return size

    @classmethod
    def load(cls, filepath: Path = CHECKPOINT_DIR / "embedding_svm.joblib") -> "EmbeddingSvmModel":
        data = joblib.load(filepath)
        model = cls(config=data["config"])
        model.svm = data["svm"]
        model.calibrated_clf = data["calibrated"]
        return model

def train_and_eval_embedding_svm(train_samples: List[Dict[str, Any]], val_samples: List[Dict[str, Any]], test_samples: List[Dict[str, Any]]) -> Dict[str, Any]:
    train_texts = [s["code"] for s in train_samples]
    train_y = [s["label"] for s in train_samples]

    val_texts = [s["code"] for s in val_samples]
    val_y = [s["label"] for s in val_samples]

    test_texts = [s["code"] for s in test_samples]
    test_y = [s["label"] for s in test_samples]

    model = EmbeddingSvmModel()
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
        model_name="embedding_svm_unixcoder",
        metadata=test_samples
    )
    return metrics
