"""
Baseline 2: TF-IDF + Random Forest.
Extracts n-gram TF-IDF features and trains an ensemble of decision trees.
Outputs probability estimates and standard classification metrics.
"""

import time
import joblib
from pathlib import Path
from typing import List, Dict, Any, Tuple, Optional
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.ensemble import RandomForestClassifier

from src.config import TfidfRfConfig, CHECKPOINT_DIR
from src.evaluation.metrics import evaluate_predictions

class TfidfRfModel:
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
        print(f"[TF-IDF+RF] Extracting features from {len(texts)} samples...", flush=True)
        X = self.vectorizer.fit_transform(texts)
        print(f"[TF-IDF+RF] Training Random Forest on matrix {X.shape}...", flush=True)
        self.rf.fit(X, y)
        duration = time.time() - t0
        print(f"[TF-IDF+RF] Training completed in {duration:.2f}s", flush=True)
        return duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[float], float]:
        t0 = time.time()
        X = self.vectorizer.transform(texts)
        probs = self.rf.predict_proba(X)[:, 1]
        preds = (probs >= 0.5).astype(int)
        duration = time.time() - t0
        return preds.tolist(), probs.tolist(), duration

    def save(self, filepath: Path = CHECKPOINT_DIR / "tfidf_rf.joblib") -> int:
        filepath.parent.mkdir(parents=True, exist_ok=True)
        joblib.dump({"vectorizer": self.vectorizer, "rf": self.rf, "config": self.config}, filepath)
        size = filepath.stat().st_size
        print(f"[TF-IDF+RF] Checkpoint saved: {filepath} ({size / (1024*1024):.2f} MB)", flush=True)
        return size

    @classmethod
    def load(cls, filepath: Path = CHECKPOINT_DIR / "tfidf_rf.joblib") -> "TfidfRfModel":
        data = joblib.load(filepath)
        model = cls(config=data["config"])
        model.vectorizer = data["vectorizer"]
        model.rf = data["rf"]
        return model

def train_and_eval_tfidf_rf(train_samples: List[Dict[str, Any]], val_samples: List[Dict[str, Any]], test_samples: List[Dict[str, Any]]) -> Dict[str, Any]:
    train_texts = [s["code"] for s in train_samples]
    train_y = [s["label"] for s in train_samples]

    test_texts = [s["code"] for s in test_samples]
    test_y = [s["label"] for s in test_samples]

    model = TfidfRfModel()
    train_duration = model.fit(train_texts, train_y)
    model_size = model.save()

    preds, probs, infer_duration = model.predict(test_texts)

    metrics = evaluate_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_duration,
        inference_duration=infer_duration,
        model_size_bytes=model_size,
        model_name="tfidf_random_forest",
        metadata=test_samples
    )
    return metrics
