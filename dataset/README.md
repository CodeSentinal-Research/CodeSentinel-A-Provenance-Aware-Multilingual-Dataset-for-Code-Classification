# CodeSentinel Dataset & Splits

This folder contains the serialized CodeSentinel corpus (`50,532` samples across 5 languages and 4 AI generators) and the leakage-free DSU-grouped split manifests.

## Contents

- `normalized_dataset.jsonl.gz` (`18.35 MB` compressed; `128.83 MB` uncompressed) — Full normalized dataset (`50,532` samples: `14,648` human, `35,884` AI) with `sample_id`, `code`, `label`, `language`, `generator`, `problem_id`, `raw_sha256`, and `norm_sha256`.
- `splits/`
  - `standard_train_manifest.jsonl` (`35,372` samples)
  - `standard_val_manifest.jsonl` (`7,579` samples)
  - `standard_test_manifest.jsonl` (`7,581` samples)
  - `standard_split_summary.json`
  - `heldout_deepseek_train_manifest.jsonl` (`28,970` samples)
  - `heldout_deepseek_val_manifest.jsonl` (`6,333` samples)
  - `heldout_deepseek_test_manifest.jsonl` (`7,581` samples)
  - `heldout_deepseek_split_summary.json`

## Decompressing

```bash
gzip -d dataset/normalized_dataset.jsonl.gz
```
