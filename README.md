# CodeSentinel

**CodeSentinel: A Provenance-Aware Multilingual Dataset for Human-Written and AI-Generated Code Classification**

[![Python 3.10](https://img.shields.io/badge/python-3.10-blue.svg)](https://www.python.org/)

CodeSentinel is a multilingual research benchmark and dual-task evaluation pipeline for:
- **Task A (Binary Detection):** Classifying source code as human-labelled (`0`) or AI-labelled (`1`).
- **Task B (4-Class Generator Attribution):** Attributing AI-labelled code to one of four generator groups (`chatgpt`, `deepseek`, `gemini`, `qwen`) using selective loss masking (`ignore_index=-100`) on human samples.

---

## Dataset Summary (Verified Manifests)

- **Total Samples:** `50,532` (`14,648` human-labelled [28.99%], `35,884` AI-labelled [71.01%])
- **Languages (5):** `c` (`10,057`), `cpp` (`9,209`), `java` (`10,682`), `javascript` (`9,924`), `python` (`10,660`)
- **AI Generator Groups (4):** `chatgpt` (`8,354`), `deepseek` (`9,202`), `gemini` (`9,218`), `qwen` (`9,110`)
- **Standard Split (`70/15/15`, DSU-grouped, seed `42`):** Train `35,372` | Val `7,579` | Test `7,581` (`0` cross-split sample or normalised-hash overlap)
- **DeepSeek Held-Out Split:** Train `28,970` | Val `6,333` | Test `7,581` (`42,884` total; DeepSeek [`1,554`] appears only in Test)

> **Dataset & Checkpoint Availability Note:** Large serialized datasets (`outputs/processed_data/`), split manifests (`outputs/splits/*.jsonl`), and model checkpoints (`outputs/checkpoints/`) are excluded from Git via `.gitignore` and are not hosted in this repository. Public dataset redistribution remains pending per-file licence verification for GitHub-sourced human code, IBM Project CodeNet attribution compliance, and terms-of-use review for the four AI generator groups.

---

## Repository Structure

```text
.
├── run_experiments.py              # Master CLI orchestrator
├── src/
│   ├── config.py                   # Paths, seeds (42), hyperparameters, hardware detection
│   ├── data/
│   │   ├── ingestion.py            # Dataset scanning, metadata lookup, raw/norm SHA-256
│   │   ├── audit.py                # Duplicate & missing-field audit
│   │   └── splitter.py             # DSU group-isolated 70/15/15 & held-out split generator
│   ├── models/
│   │   ├── tfidf_svm.py            # TF-IDF + Linear SVM (Task A)
│   │   ├── tfidf_rf.py             # TF-IDF + Random Forest (Task A)
│   │   ├── embedding_svm.py        # UniXcoder embeddings + Linear SVM (Task A)
│   │   ├── codeberta_model.py      # Independent CodeBERTa-small-v1 (Task A)
│   │   ├── codet5_model.py         # CodeT5-small (Task A only)
│   │   ├── generator_classifiers.py# Task B classifiers (SVM, RF, UniXcoder, CodeBERTa)
│   │   └── multitask_model.py      # Shared CodeBERTa Multi-Task (Task A + Task B)
│   ├── evaluation/
│   │   ├── metrics.py              # Task A metric computation
│   │   ├── generator_metrics.py    # Task B metric computation
│   │   ├── analysis.py             # Bootstrap CI & per-language/generator error analysis
│   │   └── reporting.py            # Comparison tables & visualizations
│   └── utils/
│       └── cooldown.py             # GPU thermal cooldown manager
└── tests/
    ├── test_pipeline.py            # Ingestion, DSU split, metric, and TF-IDF smoke tests
    └── test_dual_classification.py # Multi-task masking & Task B evaluation tests
```

---

## Installation & Usage

```bash
# 1. Install dependencies (Python 3.10 recommended)
pip install torch transformers scikit-learn pandas numpy matplotlib seaborn joblib

# 2. Run unit & smoke tests
python -m unittest discover -s tests -v

# 3. Prepare normalized dataset, audit, and splits (requires local dataset/)
python run_experiments.py --prepare_data

# 4. Run smoke test or full experiments
python run_experiments.py --smoke_test
python run_experiments.py --models tfidf_svm tfidf_rf embedding_svm codet5 codeberta multitask
python run_experiments.py --source_held_out deepseek
python run_experiments.py --generate_reports
```

---

## Verified Baseline Results (Standard Test Split, `n = 7,581` Task A / `n = 6,100` Task B)

| Model | Task A Acc. | Task A Macro-F1 | Task B Acc. | Task B Macro-F1 | Combined Macro-F1 |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **CodeBERTa-Small (Independent)** | 0.99657 | 0.99455 | 0.99557 | 0.99561 | 0.99508 |
| **CodeBERTa Shared Multi-Task** | 0.99604 | 0.99371 | 0.99475 | 0.99480 | 0.99425 |
| **CodeT5-Small** *(Task-A-only)* | 0.99261 | 0.98814 | — | — | — |
| **TF-IDF + Linear SVM** | 0.98997 | 0.98408 | 0.98689 | 0.98699 | 0.98554 |
| **TF-IDF + Random Forest** | 0.94381 | 0.89989 | 0.95754 | 0.95789 | 0.92889 |
| **UniXcoder + Linear SVM** | 0.94025 | 0.90862 | 0.92295 | 0.92333 | 0.91597 |

---

## Known Limitations

- **Unmatched Human & AI Problems:** Human (`p00000`–`p03999`) and AI (`P000001`–`P001865`) problem IDs occupy disjoint namespaces and are not cross-mapped.
- **Validation Logs:** Pre-cleaning compiler validation logs exist only for the C CodeNet subset (`1,500` raw → `1,181` pass).
- **AI Provenance:** Exact model versions, dates, and prompts are not recorded in the manifests.
- **Unseen Generator Generalisation:** TF-IDF + Linear SVM detection on held-out DeepSeek drops to `35.78%` (`556/1,554`; overall Task A accuracy `86.32%`).

---

## Citation & License

See `CITATION.cff` for citation metadata. No repository-level `LICENSE` file is currently present; code licensing and third-party dataset redistribution terms remain to be finalized.
