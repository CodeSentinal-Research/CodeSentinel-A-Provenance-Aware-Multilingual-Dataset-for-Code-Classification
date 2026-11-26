"""
Baseline 1: Character/Token TF-IDF + Linear SVM.
Extracts multi-granular n-gram features (char 3-5 and word 1-2),
fits Linear SVM with probability calibration, and saves checkpoint & metrics.
"""

import time
import joblib
from pathlib import Path
from typing import List, Dict, Any, Tuple, Optional
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.pipeline import FeatureUnion
from sklearn.svm import LinearSVC
from sklearn.calibration import CalibratedClassifierCV

from src.config import TfidfSvmConfig, CHECKPOINT_DIR
from src.evaluation.metrics import evaluate_predictions

class TfidfSvmModel:
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
        print(f"[TF-IDF+SVM] Extracting features from {len(texts)} training samples...", flush=True)
        X_train = self.vectorizer.fit_transform(texts)
        print(f"[TF-IDF+SVM] Training Linear SVM on matrix shape {X_train.shape}...", flush=True)
        self.svm.fit(X_train, y)

        # Calibrate for probability estimation
        from collections import Counter
        min_class_count = min(Counter(y).values()) if y else 0

        if val_texts is not None and val_y is not None and len(val_texts) >= 2:
            X_val = self.vectorizer.transform(val_texts)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv="prefit")
            self.calibrated_clf.fit(X_val, val_y)
        elif min_class_count >= 3:
            cv = min(3, min_class_count)
            self.calibrated_clf = CalibratedClassifierCV(estimator=self.svm, cv=cv)
            self.calibrated_clf.fit(X_train, y)
        else:
            self.calibrated_clf = None

        duration = time.time() - t0
        print(f"[TF-IDF+SVM] Training completed in {duration:.2f}s", flush=True)
        return duration

    def predict(self, texts: List[str]) -> Tuple[List[int], List[float], float]:
        t0 = time.time()
        X = self.vectorizer.transform(texts)
        if self.calibrated_clf is not None:
            probs = self.calibrated_clf.predict_proba(X)[:, 1]
            preds = (probs >= 0.5).astype(int)
        else:
            preds = self.svm.predict(X)
            # Use decision function transformed with sigmoid
            df = self.svm.decision_function(X)
            probs = 1.0 / (1.0 + np.exp(-df))
        duration = time.time() - t0
        return preds.tolist(), probs.tolist(), duration

    def save(self, filepath: Path = CHECKPOINT_DIR / "tfidf_svm.joblib") -> int:
        filepath.parent.mkdir(parents=True, exist_ok=True)
        joblib.dump({"vectorizer": self.vectorizer, "svm": self.svm, "calibrated": self.calibrated_clf, "config": self.config}, filepath)
        size = filepath.stat().st_size
        print(f"[TF-IDF+SVM] Checkpoint saved: {filepath} ({size / (1024*1024):.2f} MB)", flush=True)
        return size

    @classmethod
    def load(cls, filepath: Path = CHECKPOINT_DIR / "tfidf_svm.joblib") -> "TfidfSvmModel":
        data = joblib.load(filepath)
        model = cls(config=data["config"])
        model.vectorizer = data["vectorizer"]
        model.svm = data["svm"]
        model.calibrated_clf = data["calibrated"]
        return model

def train_and_eval_tfidf_svm(train_samples: List[Dict[str, Any]], val_samples: List[Dict[str, Any]], test_samples: List[Dict[str, Any]]) -> Dict[str, Any]:
    train_texts = [s["code"] for s in train_samples]
    train_y = [s["label"] for s in train_samples]

    val_texts = [s["code"] for s in val_samples]
    val_y = [s["label"] for s in val_samples]

    test_texts = [s["code"] for s in test_samples]
    test_y = [s["label"] for s in test_samples]

    model = TfidfSvmModel()
    train_duration = model.fit(train_texts, train_y, val_texts, val_y)
    model_size = model.save()

    # Inference on test set
    preds, probs, infer_duration = model.predict(test_texts)

    metrics = evaluate_predictions(
        y_true=test_y,
        y_pred=preds,
        y_prob=probs,
        training_duration=train_duration,
        inference_duration=infer_duration,
        model_size_bytes=model_size,
        model_name="tfidf_linear_svm",
        metadata=test_samples
    )
    return metrics
