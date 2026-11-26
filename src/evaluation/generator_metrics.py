"""
Task B Evaluation Metrics Module: AI Generator Multiclass Classification.
========================================================================
Evaluates multiclass identification among the four verified AI generators:
['chatgpt', 'deepseek', 'gemini', 'qwen'].

Key Requirements:
- Strictly evaluates only on AI-generated code with reliable generator provenance.
- Evaluates overall accuracy, macro-F1, weighted-F1.
- Computes per-generator precision, recall, F1, and support.
- Computes 4x4 multiclass confusion matrix (raw counts and row-normalized percentages).
- Computes per-language generator-classification results.
- Saves machine-readable JSON metrics and per-sample predictions CSV.
"""

import json
from pathlib import Path
from typing import Dict, Any, List, Optional, Union
import numpy as np
import pandas as pd
from sklearn.metrics import (
    accuracy_score,
    precision_recall_fscore_support,
    confusion_matrix,
)

from src.config import METRICS_DIR, REPORTS_DIR, AI_GENERATORS, GENERATOR2ID, ID2GENERATOR, LANGUAGES


def evaluate_generator_predictions(
    y_true: List[Union[int, str]],
    y_pred: List[Union[int, str]],
    y_prob: Optional[List[List[float]]] = None,
    training_duration: float = 0.0,
    inference_duration: float = 0.0,
    model_size_bytes: int = 0,
    model_name: str = "generator_classifier",
    metadata: Optional[List[Dict[str, Any]]] = None,
    save_dir: Path = METRICS_DIR,
    reports_dir: Path = REPORTS_DIR,
) -> Dict[str, Any]:
    """
    Evaluates Task B multiclass predictions strictly on verified AI-generated samples.
    """
    # Normalize labels to integer indices 0..3
    def to_idx(lbl):
        if isinstance(lbl, (int, np.integer)):
            return int(lbl)
        if isinstance(lbl, str):
            lbl_lower = lbl.lower().strip()
            if lbl_lower in GENERATOR2ID:
                return GENERATOR2ID[lbl_lower]
        raise ValueError(f"Invalid generator label '{lbl}'. Must be one of {AI_GENERATORS}")

    int_true = [to_idx(x) for x in y_true]
    int_pred = [to_idx(x) for x in y_pred]

    y_true_arr = np.array(int_true)
    y_pred_arr = np.array(int_pred)
    n_samples = len(y_true_arr)

    # Core multiclass metrics
    acc = float(accuracy_score(y_true_arr, y_pred_arr))

    # Per-generator metrics for each class 0..3
    p_per_gen, r_per_gen, f1_per_gen, support_per_gen = precision_recall_fscore_support(
        y_true_arr, y_pred_arr, labels=list(range(len(AI_GENERATORS))), zero_division=0
    )

    # Macro & Weighted F1
    _, _, macro_f1, _ = precision_recall_fscore_support(y_true_arr, y_pred_arr, average="macro", zero_division=0)
    _, _, weighted_f1, _ = precision_recall_fscore_support(y_true_arr, y_pred_arr, average="weighted", zero_division=0)

    # 4x4 Multiclass Confusion Matrix
    cm_raw = confusion_matrix(y_true_arr, y_pred_arr, labels=list(range(len(AI_GENERATORS))))
    cm_norm = cm_raw / np.maximum(cm_raw.sum(axis=1, keepdims=True), 1e-9)

    # Per-generator structured dictionary
    per_generator_dict = {}
    for idx, gen in enumerate(AI_GENERATORS):
        pred_cnt = int(np.sum(y_pred_arr == idx))
        per_generator_dict[gen] = {
            "class_index": idx,
            "precision": round(float(p_per_gen[idx]), 5),
            "recall": round(float(r_per_gen[idx]), 5),
            "f1_score": round(float(f1_per_gen[idx]), 5),
            "support": int(support_per_gen[idx]),
            "predicted_count": pred_cnt
        }

    # Per-language generator-classification breakdown
    per_language_dict = {}
    pred_records = []
    if metadata and len(metadata) == n_samples:
        for i in range(n_samples):
            item = metadata[i]
            t_gen = ID2GENERATOR[int_true[i]]
            p_gen = ID2GENERATOR[int_pred[i]]
            probs = y_prob[i] if y_prob is not None else None
            pred_records.append({
                "sample_id": item.get("sample_id"),
                "language": item.get("language"),
                "generator": item.get("generator"),
                "true_generator": t_gen,
                "pred_generator": p_gen,
                "is_correct": int(int_true[i] == int_pred[i]),
                "probabilities": probs
            })

        df_preds = pd.DataFrame(pred_records)
        for lang in LANGUAGES:
            sub = df_preds[df_preds["language"] == lang]
            if len(sub) == 0:
                continue
            sub_true = [GENERATOR2ID[g] for g in sub["true_generator"]]
            sub_pred = [GENERATOR2ID[g] for g in sub["pred_generator"]]
            lang_acc = float(accuracy_score(sub_true, sub_pred))
            _, _, lang_f1, _ = precision_recall_fscore_support(sub_true, sub_pred, average="macro", zero_division=0)

            lang_per_gen_recall = {}
            for g_idx, g_name in enumerate(AI_GENERATORS):
                g_sub = sub[sub["true_generator"] == g_name]
                if len(g_sub) > 0:
                    lang_per_gen_recall[g_name] = round(float(np.mean(g_sub["pred_generator"] == g_name)), 4)
                else:
                    lang_per_gen_recall[g_name] = 0.0

            per_language_dict[lang] = {
                "ai_samples": len(sub),
                "accuracy": round(lang_acc, 5),
                "macro_f1": round(float(lang_f1), 5),
                "per_generator_recall": lang_per_gen_recall
            }

    latency_per_sample_ms = (
        float(inference_duration / n_samples * 1000.0) if n_samples > 0 else 0.0
    )
    model_size_mb = float(model_size_bytes / (1024 * 1024))

    metrics_payload = {
        "model_name": model_name,
        "task": "Task B: AI Generator Classification (4-class)",
        "generator_classes": AI_GENERATORS,
        "eligible_ai_sample_counts": {
            "total_evaluated": n_samples,
            "per_generator_actual": {gen: int(support_per_gen[i]) for i, gen in enumerate(AI_GENERATORS)},
            "per_generator_predicted": {gen: int(np.sum(y_pred_arr == i)) for i, gen in enumerate(AI_GENERATORS)}
        },
        "accuracy": round(acc, 5),
        "macro_f1": round(float(macro_f1), 5),
        "weighted_f1": round(float(weighted_f1), 5),
        "per_generator_metrics": per_generator_dict,
        "confusion_matrix": {
            "labels": AI_GENERATORS,
            "raw_counts": cm_raw.tolist(),
            "normalized_rates": np.round(cm_norm, 5).tolist()
        },
        "per_language_generator_performance": per_language_dict,
        "computational_profile": {
            "training_duration_seconds": round(training_duration, 2),
            "inference_duration_seconds": round(inference_duration, 2),
            "latency_ms_per_sample": round(latency_per_sample_ms, 3),
            "model_size_mb": round(model_size_mb, 2)
        }
    }

    # Save metrics JSON & reports
    base_name = model_name if model_name.endswith("_task_b") else f"{model_name}_task_b"
    save_dir.mkdir(parents=True, exist_ok=True)
    json_path = save_dir / f"{base_name}_metrics.json"
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump(metrics_payload, f, indent=2)

    # Save detailed CSVs
    if pred_records:
        csv_path = save_dir / f"{base_name}_predictions.csv"
        pd.DataFrame(pred_records).to_csv(csv_path, index=False)

    reports_dir.mkdir(parents=True, exist_ok=True)
    pd.DataFrame.from_dict(per_generator_dict, orient="index").to_csv(reports_dir / f"{base_name}_per_generator.csv")
    if per_language_dict:
        pd.DataFrame.from_dict(per_language_dict, orient="index").to_csv(reports_dir / f"{base_name}_per_language.csv")

    print(
        f"[Task B Eval] {model_name} -> Acc: {metrics_payload['accuracy']:.4f} | "
        f"Macro-F1: {metrics_payload['macro_f1']:.4f} | "
        f"ChatGPT F1: {per_generator_dict['chatgpt']['f1_score']:.4f} | "
        f"DeepSeek F1: {per_generator_dict['deepseek']['f1_score']:.4f} | "
        f"Gemini F1: {per_generator_dict['gemini']['f1_score']:.4f} | "
        f"Qwen F1: {per_generator_dict['qwen']['f1_score']:.4f}",
        flush=True
    )
    return metrics_payload
