# CodeSentinel — Final Research & Reproducibility Audit Report

**Date:** 2026-11-27  
**Workspace:** `C:\Users\srika\OneDrive\Desktop\clg-proj\detaset_training_details`  
**GitHub Remote:** `https://github.com/srikarlab/codesentinal_details` (`main` @ `426b3cc`, pushed `2026-11-26T16:26:02Z`)  

---

## 1. Audit Scope & Verified Dataset Inventory

All counts were independently verified against `outputs/processed_data/normalized_dataset.jsonl`, `outputs/reports/data_audit_report.json`, and `outputs/splits/*.json` / `*.jsonl`:
- **Total Corpus:** `50,532` samples (`14,648` human-labelled [28.99%], `35,884` AI-labelled [71.01%]; `1` empty AI file: `c_ai_gemini_C_GEMINI_P000082`).
- **Languages:** `C` (`10,057`), `C++` (`9,209`), `Java` (`10,682`), `JavaScript` (`9,924`), `Python` (`10,660`).
- **AI Generators:** `ChatGPT` (`8,354`), `DeepSeek` (`9,202`), `Gemini` (`9,218`), `Qwen` (`9,110`).
- **Standard Split (`70/15/15`, seed `42`):** Train `35,372` | Val `7,579` | Test `7,581` (`1,481` human, `6,100` AI).
- **DeepSeek Held-Out Split:** Train `28,970` | Val `6,333` | Test `7,581` (`42,884` total = `50,532 − 7,648`; DeepSeek appears only in Test with `1,554` samples).

---

## 2. Leakage, Duplicate & Problem-Group Audit

- **Sample-Level & Hash Leakage:** Verified `0` cross-split sample ID overlap, `0` raw SHA-256 overlap, and `0` whitespace-normalized SHA-256 overlap in both Standard and DeepSeek-Held-Out splits.
- **Duplicate Groups (`data_audit_report.json`):** `1,473` exact raw-hash groups (`3,297` files) and `1,652` whitespace-normalized groups (`3,791` files), kept intact inside single DSU clusters; `0` cross-label raw or normalized collisions.
- **Problem-Level Grouping (`splitter.py`):** DSU clusters link samples by `raw_sha256`, `norm_sha256`, and within-source `problem_id` (`11,063` clusters, `0` cross-split `problem_id` overlap). **Critical limitation:** `splitter.py` prefixes `human_prob_` (`p00000`–`p03999`) separately from `ai_prob_` (`P000001`–`P001865`, `1,843` unique IDs), so human and AI problems are **not** cross-mapped.

---

## 3. Experimental Verification, Statistics, Calibration & Error Analysis

- **Metric Verification:** Recomputed Task A (`n = 7,581`) and Task B (`n = 6,100`) metrics from all saved prediction CSVs in `outputs/metrics/`; all values match `model_comparison_table.csv`, `multitask_comparison_table.csv`, and `heldout_deepseek_tfidf_linear_svm_metrics.json` to 5 decimal places.
- **Statistical Robustness (1,000-resample Bootstrap, seed `42`, & Paired McNemar Tests):**
  - Independent CodeBERTa vs. Shared Multi-Task CodeBERTa is **not statistically significant** on Task A (`p = 0.6265`) or Task B (`p = 0.5218`), supporting the shared model's 50% size reduction (`326.44` vs `643.79 MB`) and 65% latency reduction (`3.143` vs `9.065 ms/sample`).
  - Both CodeBERTa models significantly outperform TF-IDF + Linear SVM (`p < 10⁻⁵`) and Independent CodeBERTa outperforms CodeT5-Small (`p = 7.93 × 10⁻⁵`).
- **Calibration (10-bin ECE & Brier):** Shared Multi-Task (`ECE = 0.00252`, `Brier = 0.00348`) and Independent CodeBERTa (`ECE = 0.00319`, `Brier = 0.00302`) are well-calibrated; TF-IDF + Random Forest is poorly calibrated (`ECE = 0.10930`).
- **Error Analysis:** Independent CodeBERTa has `12` Task A FPs (`Python: 6`, `C: 3`, `C++: 2`, `JS: 1`, `Java: 0`) and `14` FNs (`DeepSeek: 12`, `Gemini: 2`); Shared Multi-Task has `14` FPs and `16` FNs (`DeepSeek: 13`, `Gemini: 2`, `Qwen: 1`), with `Java` at `100.00%` accuracy for both.

---

## 4. Repository, Tests, Availability & Licensing

- **Tests Executed:** `py -3.10 -m unittest discover -s tests -v` → **10/10 tests passed in 0.161s** (note: `C:\Python314` lacks `sklearn`; `py -3.10` is the working environment).
- **Repository Improvements Added Locally (not pushed to GitHub):**
  - Created `README.md`, `CITATION.cff`, `outputs/figures/human_vs_ai_by_language.png` (Fig. 1), `CodeSentinel_Research_Paper_Final_Audited.docx`, `CodeSentinel_Experiment_Summary.md`, and `CodeSentinel_Final_Audit.json`.
- **Availability & Licensing Status (Live GitHub Check):**
  - `https://github.com/srikarlab/codesentinal_details` hosts pipeline code only (`.gitignore`, `run_experiments.py`, `src/`, `tests/`).
  - Dataset files, manifests, checkpoints, `README.md`, and `LICENSE` are **not** yet pushed to GitHub.
  - Third-party licensing for GitHub human code, CodeNet `[7]`, and AI generator outputs remains unverified.

---

## 5. Experiments Not Completed & Remaining Author Confirmations

- **Not Run:** Multi-seed retraining (`3+` seeds), leave-one-language-out neural training, and a cross-mapped human–AI problem-grouped split (because human and AI problem IDs are disjoint and full GPU retraining of transformer baselines requires ~4–6 hours).
- **Remaining Confirmations:**
  1. Confirm **Dasarapu Srikar's** author contribution in `Declarations`.
  2. Confirm **Funding** and **Competing Interests**.
  3. Push `README.md`, `CITATION.cff`, and an MIT `LICENSE` (for code) to GitHub, and decide on dataset hosting/redistribution strategy.

**Candid Submission Assessment:** **Not ready for final publication as a public dataset release** until dataset hosting, `LICENSE`, third-party redistribution terms, and Dasarapu Srikar's contribution are finalized; **scientifically coherent and reproducible** for the standard-split and DeepSeek-held-out benchmark findings.
