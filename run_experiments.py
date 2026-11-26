"""
Master Experiment Runner & Pipeline Orchestrator.
=================================================
Provides a single documented command interface for launching the entire
Human vs AI Code Classification research pipeline.

Usage:
  python run_experiments.py --prepare_data
  python run_experiments.py --smoke_test
  python run_experiments.py --models tfidf_svm tfidf_rf embedding_svm codet5 codeberta
  python run_experiments.py --source_held_out deepseek
  python run_experiments.py --generate_reports
"""

import sys
import json
import random
import argparse
import time
from pathlib import Path
from typing import List, Dict, Any, Optional, Tuple
import pandas as pd

from src.config import (
    DATA_PROCESSED_DIR,
    MANIFEST_DIR,
    METRICS_DIR,
    REPORTS_DIR,
    CHECKPOINT_DIR,
    RANDOM_SEED,
    DEVICE,
    CUDA_AVAILABLE,
    VRAM_GB,
    LANGUAGES,
    AI_GENERATORS
)
from src.data.ingestion import build_normalized_dataset, scan_dataset
from src.data.splitter import generate_splits
from src.data.audit import run_data_audit
from src.models.tfidf_svm import train_and_eval_tfidf_svm
from src.models.tfidf_rf import train_and_eval_tfidf_rf
from src.models.embedding_svm import train_and_eval_embedding_svm
from src.models.codet5_model import train_and_eval_codet5
from src.models.codeberta_model import train_and_eval_codeberta
from src.models.generator_classifiers import (
    run_tfidf_svm_task_b,
    run_tfidf_rf_task_b,
    run_embedding_svm_task_b,
    run_codeberta_task_b
)
from src.models.multitask_model import run_multitask_experiment
from src.evaluation.analysis import analyze_predictions
from src.utils.cooldown import CooldownManager


def load_manifest(manifest_path: Path) -> List[Dict[str, Any]]:
    samples = []
    with open(manifest_path, "r", encoding="utf-8") as f:
        for line in f:
            if line.strip():
                samples.append(json.loads(line))
    return samples

def prepare_pipeline_data(seed: int = RANDOM_SEED) -> Tuple[List[Dict[str, Any]], List[Dict[str, Any]], List[Dict[str, Any]]]:
    norm_file = DATA_PROCESSED_DIR / "normalized_dataset.jsonl"
    if not norm_file.exists():
        print("[Orchestrator] Step 1: Ingesting raw code files & normalizing schema...", flush=True)
        build_normalized_dataset(norm_file)

    print(f"[Orchestrator] Loading normalized dataset from {norm_file}...", flush=True)
    all_samples = load_manifest(norm_file)
    print(f"[Orchestrator] Loaded {len(all_samples)} total normalized samples.", flush=True)

    print("[Orchestrator] Step 2: Running Data Quality & Duplicate Audit...", flush=True)
    run_data_audit(all_samples)

    print("[Orchestrator] Step 3: Generating Standard Leakage-Free Splits (70/15/15)...", flush=True)
    train_s, val_s, test_s, audit = generate_splits(all_samples, output_dir=MANIFEST_DIR, seed=seed)

    print("[Orchestrator] Step 4: Generating Source-Held-Out Split (held out: DeepSeek)...", flush=True)
    generate_splits(all_samples, output_dir=MANIFEST_DIR, seed=seed, held_out_generator="deepseek")

    return train_s, val_s, test_s

def stratified_subsample(samples: List[Dict[str, Any]], limit: int, seed: int = 42) -> List[Dict[str, Any]]:
    if not limit or len(samples) <= limit:
        return samples
    rng = random.Random(seed)
    by_label: Dict[int, List[Dict[str, Any]]] = {}
    for s in samples:
        by_label.setdefault(s["label"], []).append(s)

    selected: List[Dict[str, Any]] = []
    ratio = limit / len(samples)
    for lbl, class_samples in by_label.items():
        rng.shuffle(class_samples)
        n_take = max(5, int(round(len(class_samples) * ratio)))
        selected.extend(class_samples[:n_take])

    rng.shuffle(selected)
    return selected[:limit]

def run_experiment_suite(
    models: List[str],
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]],
    sample_limit: Optional[int] = None,
    epochs: Optional[int] = None,
    cooldown_interval: float = 300.0,
    cooldown_duration: float = 30.0
) -> Dict[str, Any]:
    if sample_limit:
        print(f"[Orchestrator] Stratified subsampling to train={sample_limit} for smoke testing...", flush=True)
        train_s = stratified_subsample(train_samples, sample_limit)
        val_s = stratified_subsample(val_samples, max(60, sample_limit // 4))
        test_s = stratified_subsample(test_samples, max(60, sample_limit // 4))
    else:
        train_s, val_s, test_s = train_samples, val_samples, test_samples

    print(f"[Orchestrator] Active split counts: Train={len(train_s)}, Val={len(val_s)}, Test={len(test_s)}", flush=True)
    if cooldown_interval > 0 and cooldown_duration > 0:
        print(f"[Orchestrator] Thermal Cooldown Enabled: {cooldown_duration:.0f}s rest every {cooldown_interval/60:.1f} mins of training.", flush=True)
    results = {}
    suite_cooldown_mgr = CooldownManager(interval_seconds=cooldown_interval, cooldown_seconds=cooldown_duration, component_name="Suite Orchestrator")

    for model_name in models:
        suite_cooldown_mgr.check(f"Before {model_name}")
        m_lower = model_name.lower().strip()
        print(f"\n=======================================================", flush=True)
        print(f"  LAUNCHING EXPERIMENT: {model_name.upper()} (Device: {DEVICE})", flush=True)
        print(f"=======================================================", flush=True)

        if m_lower in ["tfidf_svm", "svm"]:
            res = train_and_eval_tfidf_svm(train_s, val_s, test_s)
            results["tfidf_svm"] = res
            analyze_predictions(METRICS_DIR / "tfidf_linear_svm_predictions.csv", "tfidf_linear_svm")

        elif m_lower in ["tfidf_rf", "rf", "random_forest"]:
            res = train_and_eval_tfidf_rf(train_s, val_s, test_s)
            results["tfidf_rf"] = res
            analyze_predictions(METRICS_DIR / "tfidf_random_forest_predictions.csv", "tfidf_random_forest")

        elif m_lower in ["embedding_svm", "embed_svm", "unixcoder"]:
            res = train_and_eval_embedding_svm(train_s, val_s, test_s)
            results["embedding_svm"] = res
            analyze_predictions(METRICS_DIR / "embedding_svm_unixcoder_predictions.csv", "embedding_svm_unixcoder")

        elif m_lower in ["codet5", "t5"]:
            ep = epochs if epochs is not None else 3
            res = train_and_eval_codet5(
                train_s, val_s, test_s, epochs=ep,
                cooldown_interval=cooldown_interval,
                cooldown_duration=cooldown_duration
            )
            results["codet5"] = res
            analyze_predictions(METRICS_DIR / "codet5_small_predictions.csv", "codet5_small")

        elif m_lower in ["codeberta", "roberta"]:
            ep = epochs if epochs is not None else 3
            res = train_and_eval_codeberta(
                train_s, val_s, test_s, epochs=ep,
                cooldown_interval=cooldown_interval,
                cooldown_duration=cooldown_duration
            )
            results["codeberta"] = res
            analyze_predictions(METRICS_DIR / "codeberta_small_predictions.csv", "codeberta_small")

        elif m_lower in ["codeberta", "roberta"]:
            ep = epochs if epochs is not None else 3
            res = train_and_eval_codeberta(
                train_s, val_s, test_s, epochs=ep,
                cooldown_interval=cooldown_interval,
                cooldown_duration=cooldown_duration
            )
            results["codeberta"] = res
            analyze_predictions(METRICS_DIR / "codeberta_small_predictions.csv", "codeberta_small")

        elif m_lower in ["multitask", "shared_multitask", "multitask_codeberta"]:
            ep = epochs if epochs is not None else 3
            res_a, res_b = run_multitask_experiment(
                train_s, val_s, test_s, epochs=ep,
                cooldown_interval=cooldown_interval,
                cooldown_duration=cooldown_duration
            )
            results["multitask_task_a"] = res_a
            results["multitask_task_b"] = res_b
            analyze_predictions(METRICS_DIR / "multitask_shared_codeberta_task_a_predictions.csv", "multitask_shared_codeberta_task_a")

        elif m_lower in ["tfidf_svm_task_b", "svm_task_b"]:
            res = run_tfidf_svm_task_b(train_s, val_s, test_s)
            results["tfidf_svm_task_b"] = res

        elif m_lower in ["tfidf_rf_task_b", "rf_task_b"]:
            res = run_tfidf_rf_task_b(train_s, val_s, test_s)
            results["tfidf_rf_task_b"] = res

        elif m_lower in ["embedding_svm_task_b", "embed_svm_task_b"]:
            res = run_embedding_svm_task_b(train_s, val_s, test_s)
            results["embedding_svm_task_b"] = res

        elif m_lower in ["codeberta_task_b"]:
            ep = epochs if epochs is not None else 3
            res = run_codeberta_task_b(
                train_s, val_s, test_s, epochs=ep,
                cooldown_interval=cooldown_interval,
                cooldown_duration=cooldown_duration
            )
            results["codeberta_task_b"] = res

        else:
            print(f"[Warning] Unknown model '{model_name}'. Skipped.", flush=True)

    return results

def run_task_b_suite(
    train_samples: List[Dict[str, Any]],
    val_samples: List[Dict[str, Any]],
    test_samples: List[Dict[str, Any]],
    models: Optional[List[str]] = None,
    epochs: Optional[int] = None,
    cooldown_interval: float = 300.0,
    cooldown_duration: float = 30.0
) -> Dict[str, Any]:
    """Runs all independent Task B (AI Generator Classification) baseline models."""
    if not models or "all" in models:
        models = ["tfidf_svm_task_b", "tfidf_rf_task_b", "embedding_svm_task_b", "codeberta_task_b"]

    print("\n=======================================================", flush=True)
    print("  LAUNCHING TASK B: AI GENERATOR CLASSIFICATION SUITE", flush=True)
    print("=======================================================", flush=True)
    return run_experiment_suite(
        models, train_samples, val_samples, test_samples,
        epochs=epochs, cooldown_interval=cooldown_interval, cooldown_duration=cooldown_duration
    )

def compile_comparison_table() -> Tuple[pd.DataFrame, pd.DataFrame, pd.DataFrame]:
    """Compiles unified tables for Task A, Task B, and Shared vs Independent comparison."""
    REPORTS_DIR.mkdir(parents=True, exist_ok=True)

    # 1. Compile Task A Comparison Table
    records_a = []
    for metric_file in METRICS_DIR.glob("*_metrics.json"):
        if "task_b" in metric_file.name:
            continue
        with open(metric_file, "r", encoding="utf-8") as f:
            d = json.load(f)
            if "human_metrics (class 0)" not in d:
                continue
            records_a.append({
                "Model": d["model_name"],
                "Test Accuracy": d["accuracy"],
                "Macro F1": d["macro_f1"],
                "Human F1": d["human_metrics (class 0)"]["f1_score"],
                "AI F1": d["ai_metrics (class 1)"]["f1_score"],
                "ROC-AUC": d.get("roc_auc"),
                "PR-AUC": d.get("pr_auc"),
                "Train Time (s)": d["computational_profile"]["training_duration_seconds"],
                "Latency (ms/sample)": d["computational_profile"]["latency_ms_per_sample"],
                "Size (MB)": d["computational_profile"]["model_size_mb"]
            })
    df_a = pd.DataFrame(records_a).sort_values("Macro F1", ascending=False) if records_a else pd.DataFrame()
    out_csv_a = REPORTS_DIR / "model_comparison_table.csv"
    if not df_a.empty:
        df_a.to_csv(out_csv_a, index=False)
        print(f"\n[Task A Summary] Comparison table ({len(df_a)} models) -> {out_csv_a}", flush=True)
        print(df_a.to_string(index=False), flush=True)

    # 2. Compile Task B Comparison Table
    records_b = []
    for metric_file in METRICS_DIR.glob("*task_b_metrics.json"):
        with open(metric_file, "r", encoding="utf-8") as f:
            d = json.load(f)
            pgm = d.get("per_generator_metrics", {})
            records_b.append({
                "Model": d["model_name"].replace("_task_b", ""),
                "Accuracy": d["accuracy"],
                "Macro F1": d["macro_f1"],
                "Weighted F1": d.get("weighted_f1"),
                "ChatGPT F1": pgm.get("chatgpt", {}).get("f1_score"),
                "DeepSeek F1": pgm.get("deepseek", {}).get("f1_score"),
                "Gemini F1": pgm.get("gemini", {}).get("f1_score"),
                "Qwen F1": pgm.get("qwen", {}).get("f1_score"),
                "ChatGPT Rec": pgm.get("chatgpt", {}).get("recall"),
                "DeepSeek Rec": pgm.get("deepseek", {}).get("recall"),
                "Gemini Rec": pgm.get("gemini", {}).get("recall"),
                "Qwen Rec": pgm.get("qwen", {}).get("recall"),
                "Train Time (s)": d["computational_profile"]["training_duration_seconds"],
                "Latency (ms/sample)": d["computational_profile"]["latency_ms_per_sample"],
                "Size (MB)": d["computational_profile"]["model_size_mb"]
            })
    df_b = pd.DataFrame(records_b).sort_values("Macro F1", ascending=False) if records_b else pd.DataFrame()
    out_csv_b = REPORTS_DIR / "generator_comparison_table.csv"
    if not df_b.empty:
        df_b.to_csv(out_csv_b, index=False)
        print(f"\n[Task B Summary] Generator comparison table ({len(df_b)} models) -> {out_csv_b}", flush=True)
        print(df_b.to_string(index=False), flush=True)

    # 3. Compile Shared vs Independent Multi-Task Comparison Table
    records_multi = []
    # Map model families
    families = [
        ("TF-IDF + Linear SVM", "tfidf_linear_svm", "tfidf_linear_svm_task_b", "Independent"),
        ("TF-IDF + Random Forest", "tfidf_random_forest", "tfidf_random_forest_task_b", "Independent"),
        ("UniXcoder + Linear SVM", "embedding_svm_unixcoder", "embedding_svm_unixcoder_task_b", "Independent"),
        ("CodeBERTa-Small", "codeberta_small", "codeberta_small_task_b", "Independent"),
        ("CodeBERTa Shared Multi-Task", "multitask_shared_codeberta_task_a", "multitask_shared_codeberta_task_b", "Shared Multi-Task"),
    ]

    for fam_name, m_a, m_b, m_type in families:
        file_a = METRICS_DIR / f"{m_a}_metrics.json"
        file_b = METRICS_DIR / f"{m_b}_metrics.json"
        if file_a.exists() and file_b.exists():
            with open(file_a, "r", encoding="utf-8") as fa, open(file_b, "r", encoding="utf-8") as fb:
                da = json.load(fa)
                db = json.load(fb)
                f1_a = da.get("macro_f1", 0.0)
                f1_b = db.get("macro_f1", 0.0)
                records_multi.append({
                    "Architecture": fam_name,
                    "Type": m_type,
                    "Task A Accuracy": da.get("accuracy"),
                    "Task A Macro F1": f1_a,
                    "Task B Accuracy": db.get("accuracy"),
                    "Task B Macro F1": f1_b,
                    "Combined Macro F1": round((f1_a + f1_b) / 2.0, 5)
                })

    df_multi = pd.DataFrame(records_multi) if records_multi else pd.DataFrame()
    out_csv_multi = REPORTS_DIR / "multitask_comparison_table.csv"
    if not df_multi.empty:
        df_multi.to_csv(out_csv_multi, index=False)
        print(f"\n[Shared vs Independent Summary] Multi-task comparison table -> {out_csv_multi}", flush=True)
        print(df_multi.to_string(index=False), flush=True)

    try:
        from src.evaluation.visualizations import generate_all_visualizations
        generate_all_visualizations()
    except Exception as e:
        print(f"[Warning] Failed to generate figures: {e}", flush=True)

    return df_a, df_b, df_multi

def main():
    parser = argparse.ArgumentParser(description="Human vs AI Dual-Classification Research Pipeline")
    parser.add_argument("--prepare_data", action="store_true", help="Run ingestion, audit, and split generation")
    parser.add_argument("--smoke_test", action="store_true", help="Run quick smoke test across models")
    parser.add_argument("--models", nargs="+", default=None, help="Models to train: tfidf_svm, tfidf_rf, embedding_svm, codet5, codeberta, or all")
    parser.add_argument("--model", type=str, default=None, help="Single model to train")
    parser.add_argument("--task_b", action="store_true", help="Train and evaluate Task B (AI Generator Classification)")
    parser.add_argument("--multitask", action="store_true", help="Train and evaluate Shared Multi-Task Model (Task A + Task B)")
    parser.add_argument("--dual_eval", action="store_true", help="Run all Task A, Task B, and Shared Multi-Task experiments")
    parser.add_argument("--source_held_out", type=str, default=None, help="Run source-held-out evaluation for specified generator (e.g. deepseek)")
    parser.add_argument("--generate_reports", action="store_true", help="Compile comparison tables and research reports")
    parser.add_argument("--sample_limit", type=int, default=None, help="Limit sample count for training")
    parser.add_argument("--epochs", type=int, default=None, help="Epoch count for neural models")
    parser.add_argument("--seed", type=int, default=RANDOM_SEED, help="Random seed")
    parser.add_argument("--cooldown_interval", type=float, default=300.0, help="Interval in seconds between cooldown pauses (default 300s = 5 mins)")
    parser.add_argument("--cooldown_duration", type=float, default=30.0, help="Duration in seconds of each cooldown pause (default 30s)")
    parser.add_argument("--disable_cooldown", action="store_true", help="Disable cooldown pauses")

    args = parser.parse_args()

    cd_interval = 0.0 if args.disable_cooldown else args.cooldown_interval
    cd_duration = 0.0 if args.disable_cooldown else args.cooldown_duration

    # Determine split directory & files
    if args.source_held_out:
        gen = args.source_held_out.lower()
        train_m = MANIFEST_DIR / f"heldout_{gen}_train_manifest.jsonl"
        val_m = MANIFEST_DIR / f"heldout_{gen}_val_manifest.jsonl"
        test_m = MANIFEST_DIR / f"heldout_{gen}_test_manifest.jsonl"
    else:
        train_m = MANIFEST_DIR / "standard_train_manifest.jsonl"
        val_m = MANIFEST_DIR / "standard_val_manifest.jsonl"
        test_m = MANIFEST_DIR / "standard_test_manifest.jsonl"

    if args.prepare_data or not (train_m.exists() and val_m.exists() and test_m.exists()):
        train_samples, val_samples, test_samples = prepare_pipeline_data(seed=args.seed)
    else:
        train_samples = load_manifest(train_m)
        val_samples = load_manifest(val_m)
        test_samples = load_manifest(test_m)

    # Execution Mode: Task B Suite
    if args.task_b:
        run_task_b_suite(
            train_samples, val_samples, test_samples,
            models=args.models, epochs=args.epochs,
            cooldown_interval=cd_interval, cooldown_duration=cd_duration
        )
        compile_comparison_table()
        return

    # Execution Mode: MultiTask Shared Model
    if args.multitask:
        run_experiment_suite(
            ["multitask"], train_samples, val_samples, test_samples,
            epochs=args.epochs, sample_limit=args.sample_limit,
            cooldown_interval=cd_interval, cooldown_duration=cd_duration
        )
        compile_comparison_table()
        return

    # Execution Mode: Dual Evaluation (Task B + Shared MultiTask + Reports)
    if args.dual_eval:
        print("\n=======================================================", flush=True)
        print("  LAUNCHING COMPLETE DUAL-CLASSIFICATION RESEARCH PIPELINE", flush=True)
        print("=======================================================", flush=True)
        run_task_b_suite(
            train_samples, val_samples, test_samples,
            epochs=args.epochs, cooldown_interval=cd_interval, cooldown_duration=cd_duration
        )
        run_experiment_suite(
            ["multitask"], train_samples, val_samples, test_samples,
            epochs=args.epochs, sample_limit=args.sample_limit,
            cooldown_interval=cd_interval, cooldown_duration=cd_duration
        )
        compile_comparison_table()
        return

    # Determine models
    if args.model:
        selected_models = [args.model]
    elif args.models:
        selected_models = args.models
    else:
        selected_models = ["all"]

    if "all" in selected_models:
        selected_models = ["tfidf_svm", "tfidf_rf", "embedding_svm", "codet5", "codeberta"]

    if args.smoke_test:
        limit = args.sample_limit or 200
        ep = args.epochs or 1
        print(f"[Orchestrator] Running SMOKE TEST with limit={limit}, epochs={ep}...", flush=True)
        run_experiment_suite(
            selected_models, train_samples, val_samples, test_samples,
            sample_limit=limit, epochs=ep,
            cooldown_interval=cd_interval, cooldown_duration=cd_duration
        )
        compile_comparison_table()
    elif not args.generate_reports and not args.prepare_data:
        run_experiment_suite(
            selected_models, train_samples, val_samples, test_samples,
            sample_limit=args.sample_limit, epochs=args.epochs,
            cooldown_interval=cd_interval, cooldown_duration=cd_duration
        )
        compile_comparison_table()

    if args.generate_reports:
        compile_comparison_table()

if __name__ == "__main__":
    main()

