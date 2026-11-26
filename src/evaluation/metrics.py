"""
Unified Evaluation Metrics Module.
Calculates standardized evaluation metrics across all baseline models:
- Accuracy, Precision, Recall, and F1 for both classes (0=Human, 1=AI)
- Macro-F1 and Weighted-F1
- ROC-AUC and PR-AUC (Average Precision)
- Confusion Matrix (TN, FP, FN, TP)
- Training duration, total inference time, and per-sample inference latency
- Model checkpoint size
- Saves machine-readable JSON metrics and per-sample CSV predictions.
"""

import time
import json
from pathlib import Path
from typing import Dict, Any, List, Optional
import numpy as np
import pandas as pd
from sklearn.metrics import (
    accuracy_score,
    precision_recall_fscore_support,
    roc_auc_score,
    average_precision_score,
    confusion_matrix,
)

from src.config import METRICS_DIR

def evaluate_predictions(
    y_true: List[int],
    y_pred: List[int],
    y_prob: Optional[List[float]] = None,
    training_duration: float = 0.0,
    inference_duration: float = 0.0,
    model_size_bytes: int = 0,
    model_name: str = "model",
    metadata: Optional[List[Dict[str, Any]]] = None,
    save_dir: Path = METRICS_DIR
) -> Dict[str, Any]:
    """
    Evaluates predictions against ground truth and saves machine-readable metrics and predictions.
    """
    y_true = np.array(y_true)
    y_pred = np.array(y_pred)
    n_samples = len(y_true)

    # Core classification metrics
    acc = float(accuracy_score(y_true, y_pred))

    # Per-class metrics
    p_per_class, r_per_class, f1_per_class, support = precision_recall_fscore_support(
        y_true, y_pred, labels=[0, 1], zero_division=0
    )

    # Macro & Weighted F1
    _, _, macro_f1, _ = precision_recall_fscore_support(y_true, y_pred, average="macro", zero_division=0)
    _, _, weighted_f1, _ = precision_recall_fscore_support(y_true, y_pred, average="weighted", zero_division=0)

    # Confusion Matrix
    cm = confusion_matrix(y_true, y_pred, labels=[0, 1])
    tn, fp, fn, tp = int(cm[0, 0]), int(cm[0, 1]), int(cm[1, 0]), int(cm[1, 1])

    # Probabilistic metrics
    roc_auc = None
    pr_auc = None
    if y_prob is not None:
        y_prob = np.array(y_prob)
        try:
            roc_auc = float(roc_auc_score(y_true, y_prob))
        except Exception:
            roc_auc = None
        try:
            pr_auc = float(average_precision_score(y_true, y_prob))
        except Exception:
            pr_auc = None

    latency_per_sample_ms = (
        float(inference_duration / n_samples * 1000.0) if n_samples > 0 else 0.0
    )
    model_size_mb = float(model_size_bytes / (1024 * 1024))

    metrics_payload = {
        "model_name": model_name,
        "sample_counts": {
            "total": n_samples,
            "human_actual": int(np.sum(y_true == 0)),
            "ai_actual": int(np.sum(y_true == 1)),
            "human_predicted": int(np.sum(y_pred == 0)),
            "ai_predicted": int(np.sum(y_pred == 1))
        },
        "accuracy": round(acc, 5),
        "macro_f1": round(float(macro_f1), 5),
        "weighted_f1": round(float(weighted_f1), 5),
        "human_metrics (class 0)": {
            "precision": round(float(p_per_class[0]), 5),
            "recall": round(float(r_per_class[0]), 5),
            "f1_score": round(float(f1_per_class[0]), 5),
            "support": int(support[0])
        },
        "ai_metrics (class 1)": {
            "precision": round(float(p_per_class[1]), 5),
            "recall": round(float(r_per_class[1]), 5),
            "f1_score": round(float(f1_per_class[1]), 5),
            "support": int(support[1])
        },
        "roc_auc": round(roc_auc, 5) if roc_auc is not None else None,
        "pr_auc": round(pr_auc, 5) if pr_auc is not None else None,
        "confusion_matrix": {
            "true_negative": tn,
            "false_positive": fp,
            "false_negative": fn,
            "true_positive": tp
        },
        "computational_profile": {
            "training_duration_seconds": round(training_duration, 2),
            "inference_duration_seconds": round(inference_duration, 2),
            "latency_ms_per_sample": round(latency_per_sample_ms, 3),
            "model_size_mb": round(model_size_mb, 2)
        }
    }

    # Save metrics JSON
    save_dir.mkdir(parents=True, exist_ok=True)
    json_path = save_dir / f"{model_name}_metrics.json"
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump(metrics_payload, f, indent=2)

    # Save detailed per-sample predictions CSV if metadata is provided
    if metadata and len(metadata) == n_samples:
        pred_records = []
        for i in range(n_samples):
            item = metadata[i]
            pred_records.append({
                "sample_id": item.get("sample_id"),
                "language": item.get("language"),
                "generator": item.get("generator"),
                "problem_id": item.get("problem_id"),
                "true_label": int(y_true[i]),
                "pred_label": int(y_pred[i]),
                "prob_ai": float(y_prob[i]) if y_prob is not None else None,
                "is_correct": int(y_true[i] == y_pred[i])
            })
        csv_path = save_dir / f"{model_name}_predictions.csv"
        pd.DataFrame(pred_records).to_csv(csv_path, index=False)

    print(f"[Evaluation] {model_name} -> Acc: {metrics_payload['accuracy']:.4f} | Macro-F1: {metrics_payload['macro_f1']:.4f} | ROC-AUC: {metrics_payload['roc_auc']}", flush=True)
    return metrics_payload
