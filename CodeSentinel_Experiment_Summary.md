# CodeSentinel — Verified Experimental Results Summary

## 1. Standard Split Evaluation (`n = 7,581` Task A; `n = 6,100` Task B)

| Model | Task A Acc [95% CI] | Task A Macro-F1 [95% CI] | Task B Acc [95% CI] | Task B Macro-F1 [95% CI] | Combined Macro-F1 | ECE (10-bin) | Brier |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **CodeBERTa-Small (Indep.)** | 0.99657 `[0.99512, 0.99776]` | 0.99455 `[0.99235, 0.99640]` | 0.99557 `[0.99393, 0.99721]` | 0.99561 `[0.99397, 0.99723]` | 0.99508 | 0.00319 | 0.00302 |
| **CodeBERTa Shared Multi-Task** | 0.99604 `[0.99459, 0.99736]` | 0.99371 `[0.99140, 0.99581]` | 0.99475 `[0.99279, 0.99656]` | 0.99480 `[0.99290, 0.99659]` | 0.99425 | 0.00252 | 0.00348 |
| **CodeT5-Small** *(Task-A-only)* | 0.99261 `[0.99050, 0.99459]` | 0.98814 `[0.98470, 0.99121]` | — | — | — | 0.00708 | 0.00693 |
| **TF-IDF + Linear SVM** | 0.98997 `[0.98760, 0.99209]` | 0.98408 `[0.98021, 0.98747]` | 0.98689 `[0.98377, 0.98984]` | 0.98699 `[0.98395, 0.98985]` | 0.98554 | 0.00617 | 0.00785 |
| **TF-IDF + Random Forest** | 0.94381 `[0.93813, 0.94908]` | 0.89989 `[0.88996, 0.90905]` | 0.95754 `[0.95197, 0.96262]` | 0.95789 `[0.95245, 0.96307]` | 0.92889 | 0.10930 | 0.04977 |
| **UniXcoder + Linear SVM** | 0.94025 `[0.93510, 0.94565]` | 0.90862 `[0.90100, 0.91635]` | 0.92295 `[0.91656, 0.92984]` | 0.92333 `[0.91714, 0.93011]` | 0.91597 | 0.05100 | 0.04568 |

*Bootstrap methodology: `1,000` sample-level resamples with replacement, random seed `42`.*

## 2. Paired McNemar's Tests

- **Task A (`n = 7,581`):**
  - `CodeBERTa-Small` vs `Shared Multi-Task`: `21` vs `17` discordant errors, `χ² = 0.2368`, **`p = 0.6265`** (not significant)
  - `CodeBERTa-Small` vs `TF-IDF + Linear SVM`: `72` vs `22`, `χ² = 25.5426`, **`p = 4.33 × 10⁻⁷`**
  - `Shared Multi-Task` vs `TF-IDF + Linear SVM`: `72` vs `26`, `χ² = 20.6633`, **`p = 5.48 × 10⁻⁶`**
  - `CodeBERTa-Small` vs `CodeT5-Small`: `42` vs `12`, `χ² = 15.5741`, **`p = 7.93 × 10⁻⁵`**
- **Task B (`n = 6,100`):**
  - `CodeBERTa-Small` vs `Shared Multi-Task`: `22` vs `17` discordant errors, `χ² = 0.4103`, **`p = 0.5218`** (not significant)

## 3. Task A Error Breakdown by Language

- **CodeBERTa-Small (`26` errors):** `C` (3 FP, 3 FN), `C++` (2 FP, 3 FN), `Java` (0 FP, 0 FN), `JavaScript` (1 FP, 3 FN), `Python` (6 FP, 5 FN). FNs by generator: `DeepSeek` (12), `Gemini` (2).
- **Shared Multi-Task (`30` errors):** `C` (6 FP, 6 FN), `C++` (2 FP, 4 FN), `Java` (0 FP, 0 FN), `JavaScript` (2 FP, 2 FN), `Python` (4 FP, 4 FN). FNs by generator: `DeepSeek` (13), `Gemini` (2), `Qwen` (1).

## 4. DeepSeek Held-Out Generalization (TF-IDF + Linear SVM)

- **Overall (`n = 7,581`):** Accuracy `0.86321`, Macro-F1 `0.82275`, ROC-AUC `0.98705`, PR-AUC `0.99679`.
- **DeepSeek Detection:** `556 / 1,554` (`35.78%` detected; `998` evaded).
- **Seen AI Detection:** `4,527 / 4,546` (`99.58%` detected).

## 5. Source Confounding & Leave-One-Language-Out (LOLO) Diagnostics

- **Source Confounding (Human CodeNet vs. GitHub, char 3–5-gram TF-IDF + SVM, `n_train = 10,429`, `n_test = 1,481`):** Accuracy **`0.98244`**, Macro-F1 **`0.96811`** (confirms strong lexical separation between human sources).
- **Leave-One-Language-Out (LOLO, Task A, word 1–2-gram TF-IDF + SVM):**
  - Held-out `C` (`n = 1,482`): Acc `0.38192`, Macro-F1 `0.37886`
  - Held-out `C++` (`n = 1,509`): Acc `0.67860`, Macro-F1 `0.63566`
  - Held-out `Java` (`n = 1,437`): Acc `0.81768`, Macro-F1 `0.70545`
  - Held-out `JavaScript` (`n = 1,625`): Acc `0.61538`, Macro-F1 `0.57037`
  - Held-out `Python` (`n = 1,528`): Acc `0.84162`, Macro-F1 `0.78344`
