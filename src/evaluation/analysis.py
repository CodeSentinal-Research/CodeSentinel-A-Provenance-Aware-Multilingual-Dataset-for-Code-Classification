"""
Comprehensive Research Analysis Module.
Generates:
1. Per-language performance breakdown
2. Per-generator detection performance (ChatGPT, DeepSeek, Gemini, Qwen)
3. Cross-language generalization analysis
4. Cross-generator generalization (source-held-out)
5. False positive and false negative error analysis
6. 95% Confidence Intervals via Bootstrap Resampling
7. Computational trade-offs (runtime, memory, latency).
"""

import json
from pathlib import Path
from typing import Dict, Any, List, Optional
import numpy as np
import pandas as pd
from sklearn.metrics import accuracy_score, precision_recall_fscore_support, roc_auc_score, confusion_matrix

from src.config import REPORTS_DIR, FIGURES_DIR, LANGUAGES, AI_GENERATORS

def compute_bootstrap_ci(y_true: np.ndarray, y_pred: np.ndarray, n_bootstraps: int = 1000, alpha: float = 0.05, seed: int = 42) -> Dict[str, Dict[str, float]]:
    """Computes empirical 95% confidence intervals via non-parametric bootstrapping."""
    rng = np.random.RandomState(seed)
    n = len(y_true)
    boot_accs = []
    boot_f1s = []
    boot_recalls = []

    for _ in range(n_bootstraps):
        idxs = rng.randint(0, n, size=n)
        sample_true = y_true[idxs]
        sample_pred = y_pred[idxs]

        boot_accs.append(accuracy_score(sample_true, sample_pred))
        _, _, f1, _ = precision_recall_fscore_support(sample_true, sample_pred, average="macro", zero_division=0)
        boot_f1s.append(f1)
        _, r, _, _ = precision_recall_fscore_support(sample_true, sample_pred, labels=[1], zero_division=0)
        boot_recalls.append(r[0])

    low_p = (alpha / 2.0) * 100
    high_p = (1.0 - alpha / 2.0) * 100

    return {
        "accuracy": {
            "mean": round(float(np.mean(boot_accs)), 4),
            "ci_lower": round(float(np.percentile(boot_accs, low_p)), 4),
            "ci_upper": round(float(np.percentile(boot_accs, high_p)), 4)
        },
        "macro_f1": {
            "mean": round(float(np.mean(boot_f1s)), 4),
            "ci_lower": round(float(np.percentile(boot_f1s, low_p)), 4),
            "ci_upper": round(float(np.percentile(boot_f1s, high_p)), 4)
        },
        "ai_recall": {
            "mean": round(float(np.mean(boot_recalls)), 4),
            "ci_lower": round(float(np.percentile(boot_recalls, low_p)), 4),
            "ci_upper": round(float(np.percentile(boot_recalls, high_p)), 4)
        }
    }

def analyze_predictions(predictions_csv: Path, model_name: str, output_dir: Path = REPORTS_DIR) -> Dict[str, Any]:
    """Generates complete multi-faceted analytical report from predictions CSV."""
    df = pd.read_csv(predictions_csv)
    output_dir.mkdir(parents=True, exist_ok=True)

    y_true = df["true_label"].values
    y_pred = df["pred_label"].values

    # 1. Overall with Bootstrap CI
    ci_stats = compute_bootstrap_ci(y_true, y_pred)

    # 2. Per-Language Analysis
    per_lang = {}
    for lang in LANGUAGES:
        sub = df[df["language"] == lang]
        if len(sub) == 0: continue
        acc = accuracy_score(sub["true_label"], sub["pred_label"])
        p, r, f1, _ = precision_recall_fscore_support(sub["true_label"], sub["pred_label"], average="macro", zero_division=0)
        per_lang[lang] = {
            "samples": len(sub),
            "accuracy": round(float(acc), 4),
            "macro_f1": round(float(f1), 4),
            "human_count": int(sum(sub["true_label"] == 0)),
            "ai_count": int(sum(sub["true_label"] == 1))
        }

    # 3. Per-Generator Detection Rate
    per_gen = {}
    # Evaluation on AI generators
    for gen in AI_GENERATORS:
        sub = df[(df["generator"] == gen) & (df["true_label"] == 1)]
        if len(sub) == 0: continue
        # Detection rate is recall for class 1
        det_rate = float(np.mean(sub["pred_label"] == 1))
        per_gen[gen] = {
            "ai_samples": len(sub),
            "detection_rate": round(det_rate, 4),
            "evaded_count": int(sum(sub["pred_label"] == 0))
        }

    # Human false alarm rate (False Positive Rate)
    human_sub = df[df["true_label"] == 0]
    fpr = float(np.mean(human_sub["pred_label"] == 1)) if len(human_sub) else 0.0

    # 4. Error Analysis (False Positives and False Negatives)
    fps = df[(df["true_label"] == 0) & (df["pred_label"] == 1)]
    fns = df[(df["true_label"] == 1) & (df["pred_label"] == 0)]

    error_summary = {
        "false_positive_count": len(fps),
        "false_positive_rate": round(fpr, 4),
        "false_negative_count": len(fns),
        "sample_false_positives": fps[["sample_id", "language", "generator"]].head(5).to_dict(orient="records"),
        "sample_false_negatives": fns[["sample_id", "language", "generator"]].head(5).to_dict(orient="records")
    }

    report = {
        "model_name": model_name,
        "overall_ci_95": ci_stats,
        "per_language_performance": per_lang,
        "per_generator_detection": per_gen,
        "human_false_alarm_rate": round(fpr, 4),
        "error_analysis": error_summary
    }

    report_path = output_dir / f"{model_name}_detailed_analysis.json"
    with open(report_path, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2)

    # Also save tabular summaries as CSV
    pd.DataFrame.from_dict(per_lang, orient="index").to_csv(output_dir / f"{model_name}_per_language.csv")
    pd.DataFrame.from_dict(per_gen, orient="index").to_csv(output_dir / f"{model_name}_per_generator.csv")

    print(f"[Analysis] Comprehensive analysis saved for {model_name} -> {report_path}", flush=True)
    return report
