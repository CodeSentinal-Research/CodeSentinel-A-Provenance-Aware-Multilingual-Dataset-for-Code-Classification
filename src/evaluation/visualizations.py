"""
Publication-Quality Visualization Suite for Human vs AI Code Classification.
==========================================================================
Generates high-resolution figures:
1. model_comparison_barplot.png
2. confusion_matrices_grid.png
3. per_language_performance.png
4. per_generator_performance.png
5. latency_vs_f1_tradeoff.png
"""

import json
from pathlib import Path
from typing import Dict, List, Any
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

from src.config import REPORTS_DIR, FIGURES_DIR, METRICS_DIR

# Set publication style
plt.style.use('seaborn-v0_8-whitegrid' if 'seaborn-v0_8-whitegrid' in plt.style.available else 'default')
plt.rcParams.update({
    'font.size': 11,
    'axes.labelsize': 12,
    'axes.titlesize': 13,
    'xtick.labelsize': 10,
    'ytick.labelsize': 10,
    'figure.titlesize': 15,
    'figure.dpi': 300
})

def plot_model_comparison(comparison_csv: Path = REPORTS_DIR / "model_comparison_table.csv"):
    if not comparison_csv.exists():
        return
    df = pd.read_csv(comparison_csv)
    if df.empty:
        return

    fig, ax = plt.subplots(figsize=(10, 5.5))
    metrics = ["Test Accuracy", "Macro F1", "Human F1", "AI F1"]
    df_melt = df.melt(id_vars=["Model"], value_vars=metrics, var_name="Metric", value_name="Score")

    palette = sns.color_palette("deep", len(metrics))
    sns.barplot(data=df_melt, x="Model", y="Score", hue="Metric", palette=palette, ax=ax)
    ax.set_ylim(0, 1.05)
    ax.set_title("Baseline Model Performance Comparison (Zero-Leakage Test Set)")
    ax.set_ylabel("Score (0.0 - 1.0)")
    ax.set_xlabel("Model Architecture")
    plt.xticks(rotation=15, ha='right')
    plt.legend(bbox_to_anchor=(1.02, 1), loc='upper left')
    plt.tight_layout()

    out_path = FIGURES_DIR / "model_comparison_barplot.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved model comparison barplot -> {out_path}")

def plot_confusion_matrices():
    metric_files = [
        mf for mf in METRICS_DIR.glob("*_metrics.json")
        if "task_b" not in mf.name
    ]
    if not metric_files:
        return

    n_models = len(metric_files)
    cols = min(3, n_models)
    rows = (n_models + cols - 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(5 * cols, 4.5 * rows))
    if n_models == 1:
        axes = [axes]
    else:
        axes = axes.flatten()

    for idx, mf in enumerate(metric_files):
        with open(mf, "r", encoding="utf-8") as f:
            d = json.load(f)
        cmd = d["confusion_matrix"]
        if isinstance(cmd, dict):
            cm = np.array([
                [cmd["true_negative"], cmd["false_positive"]],
                [cmd["false_negative"], cmd["true_positive"]]
            ], dtype=float)
        else:
            cm = np.array(cmd, dtype=float)

        cm_norm = cm / np.maximum(cm.sum(axis=1, keepdims=True), 1e-9)
        labels = [f"{v}\n({int(cm[i, j])})" for i, row in enumerate(cm_norm) for j, v in enumerate([f"{x:.1%}" for x in row])]
        labels = np.asarray(labels).reshape(2, 2)

        ax = axes[idx]
        sns.heatmap(cm_norm, annot=labels, fmt='', cmap="Blues", cbar=False, ax=ax,
                    xticklabels=["Human", "AI"], yticklabels=["Human", "AI"], vmin=0, vmax=1)
        ax.set_title(f"{d['model_name']}\n(Acc: {d['accuracy']:.3f} | Macro-F1: {d['macro_f1']:.3f})")
        ax.set_ylabel("True Label")
        ax.set_xlabel("Predicted Label")

    for idx in range(n_models, len(axes)):
        fig.delaxes(axes[idx])

    plt.suptitle("Normalized Confusion Matrices Across Baseline Models", y=1.02)
    plt.tight_layout()
    out_path = FIGURES_DIR / "confusion_matrices_grid.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved confusion matrices grid -> {out_path}")

def plot_per_language_breakdown():
    analysis_files = list(REPORTS_DIR.glob("*_detailed_analysis.json"))
    records = []
    for af in analysis_files:
        with open(af, "r", encoding="utf-8") as f:
            d = json.load(f)
        model = d["model_name"]
        for lang, stats in d.get("per_language_performance", {}).items():
            records.append({
                "Model": model,
                "Language": lang.upper(),
                "F1": stats.get("macro_f1", 0.0),
                "Accuracy": stats.get("accuracy", 0.0)
            })

    if not records:
        return
    df = pd.DataFrame(records)
    pivot_df = df.pivot(index="Model", columns="Language", values="F1")

    fig, ax = plt.subplots(figsize=(8, 4.5))
    sns.heatmap(pivot_df, annot=True, fmt=".3f", cmap="YlGnBu", cbar_kws={'label': 'Macro F1'}, vmin=0, vmax=1, ax=ax)
    ax.set_title("Per-Language Macro-F1 Score Breakdown")
    plt.tight_layout()
    out_path = FIGURES_DIR / "per_language_heatmap.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved per-language heatmap -> {out_path}")

def plot_per_generator_breakdown():
    analysis_files = list(REPORTS_DIR.glob("*_detailed_analysis.json"))
    records = []
    for af in analysis_files:
        with open(af, "r", encoding="utf-8") as f:
            d = json.load(f)
        model = d["model_name"]
        for gen, stats in d.get("per_generator_detection", {}).items():
            if gen.lower() != "human":
                records.append({
                    "Model": model,
                    "AI Generator": gen.capitalize(),
                    "Detection Rate": stats.get("detection_rate", 0.0)
                })

    if not records:
        return
    df = pd.DataFrame(records)
    pivot_df = df.pivot(index="Model", columns="AI Generator", values="Detection Rate")

    fig, ax = plt.subplots(figsize=(8, 4.5))
    sns.heatmap(pivot_df, annot=True, fmt=".3f", cmap="Oranges", cbar_kws={'label': 'Detection Rate'}, vmin=0, vmax=1, ax=ax)
    ax.set_title("Per-AI Generator Detection Breakdown (Recall)")
    plt.tight_layout()
    out_path = FIGURES_DIR / "per_generator_heatmap.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved per-generator heatmap -> {out_path}")

def plot_task_b_confusion_matrices():
    """Generates 4x4 multiclass confusion matrix heatmaps for all Task B models."""
    metric_files = list(METRICS_DIR.glob("*task_b_metrics.json"))
    if not metric_files:
        return

    n_models = len(metric_files)
    cols = min(2, n_models)
    rows = (n_models + cols - 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(6.5 * cols, 5.5 * rows))
    if n_models == 1:
        axes = [axes]
    else:
        axes = np.array(axes).flatten()

    for idx, mf in enumerate(metric_files):
        with open(mf, "r", encoding="utf-8") as f:
            d = json.load(f)
        cmd = d.get("confusion_matrix", {})
        labels = cmd.get("labels", ["chatgpt", "deepseek", "gemini", "qwen"])
        display_labels = [l.capitalize() for l in labels]
        raw_counts = np.array(cmd.get("raw_counts", []), dtype=int)
        norm_rates = np.array(cmd.get("normalized_rates", []), dtype=float)

        annot = []
        for i in range(len(labels)):
            row_annot = []
            for j in range(len(labels)):
                pct = norm_rates[i, j] * 100
                cnt = raw_counts[i, j]
                row_annot.append(f"{pct:.1f}%\n({cnt})")
            annot.append(row_annot)

        ax = axes[idx]
        sns.heatmap(
            norm_rates,
            annot=np.array(annot),
            fmt='',
            cmap="Purples",
            cbar=False,
            ax=ax,
            xticklabels=display_labels,
            yticklabels=display_labels,
            vmin=0,
            vmax=1
        )
        model_title = d["model_name"].replace("_task_b", "").replace("_", " ").title()
        ax.set_title(f"{model_title}\n(Acc: {d['accuracy']:.3f} | Macro-F1: {d['macro_f1']:.3f})")
        ax.set_ylabel("True AI Generator")
        ax.set_xlabel("Predicted AI Generator")

    for idx in range(n_models, len(axes)):
        fig.delaxes(axes[idx])

    plt.suptitle("Task B: 4x4 Multiclass AI Generator Confusion Matrices", y=1.02)
    plt.tight_layout()
    out_path = FIGURES_DIR / "task_b_confusion_matrices.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved Task B confusion matrices -> {out_path}")

def plot_task_b_per_language():
    """Generates per-language generator classification breakdown heatmap."""
    metric_files = list(METRICS_DIR.glob("*task_b_metrics.json"))
    records = []
    for mf in metric_files:
        with open(mf, "r", encoding="utf-8") as f:
            d = json.load(f)
        model = d["model_name"].replace("_task_b", "")
        per_lang = d.get("per_language_generator_performance", {})
        for lang, stats in per_lang.items():
            records.append({
                "Model": model,
                "Language": lang.upper(),
                "Accuracy": stats.get("accuracy", 0.0),
                "Macro F1": stats.get("macro_f1", 0.0)
            })

    if not records:
        return
    df = pd.DataFrame(records)
    pivot_df = df.pivot(index="Model", columns="Language", values="Macro F1")

    fig, ax = plt.subplots(figsize=(8, 4.5))
    sns.heatmap(pivot_df, annot=True, fmt=".3f", cmap="BuPu", cbar_kws={'label': 'Macro F1'}, vmin=0, vmax=1, ax=ax)
    ax.set_title("Task B: Per-Language Generator Classification Macro-F1")
    plt.tight_layout()
    out_path = FIGURES_DIR / "task_b_per_language_heatmap.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved Task B per-language heatmap -> {out_path}")

def plot_multitask_comparison():
    """Generates comparison barplot comparing Shared Multi-Task Model vs Independent Classifiers."""
    comp_file = REPORTS_DIR / "multitask_comparison_table.csv"
    if not comp_file.exists():
        return
    df = pd.read_csv(comp_file)
    if df.empty:
        return

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5.5))

    # Task A: Binary Classification
    sns.barplot(data=df, x="Architecture", y="Task A Macro F1", hue="Type", palette=["#3b82f6", "#10b981"], ax=ax1)
    ax1.set_ylim(0.8, 1.02)
    ax1.set_title("Task A: Human vs AI (Macro F1)")
    ax1.set_ylabel("Macro F1 Score")
    plt.setp(ax1.get_xticklabels(), rotation=20, ha='right')

    # Task B: AI Generator Multiclass Classification
    sns.barplot(data=df, x="Architecture", y="Task B Macro F1", hue="Type", palette=["#8b5cf6", "#ec4899"], ax=ax2)
    ax2.set_ylim(0.0, 1.02)
    ax2.set_title("Task B: AI Generator Identification (Macro F1)")
    ax2.set_ylabel("Macro F1 Score")
    plt.setp(ax2.get_xticklabels(), rotation=20, ha='right')

    plt.suptitle("Shared Multi-Task Model vs Separate Independent Classifiers", y=1.02)
    plt.tight_layout()
    out_path = FIGURES_DIR / "shared_vs_independent_comparison.png"
    plt.savefig(out_path, dpi=300)
    plt.close()
    print(f"[Visualizations] Saved Shared vs Independent comparison plot -> {out_path}")

def generate_all_visualizations():
    FIGURES_DIR.mkdir(parents=True, exist_ok=True)
    plot_model_comparison()
    plot_confusion_matrices()
    plot_per_language_breakdown()
    plot_per_generator_breakdown()
    plot_task_b_confusion_matrices()
    plot_task_b_per_language()
    plot_multitask_comparison()

if __name__ == "__main__":
    generate_all_visualizations()

