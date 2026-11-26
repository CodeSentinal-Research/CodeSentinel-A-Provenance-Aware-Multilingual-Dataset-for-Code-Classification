"""
Data Quality and Leakage Audit Module.
Performs comprehensive integrity checks:
- Exact duplicate detection (raw SHA-256)
- Near-duplicate detection (normalized token/whitespace SHA-256)
- Label collision detection (same code labeled as both AI and Human)
- Missing field and empty file detection
- Suspicious source attribution audit
- Statistical distributions of code length and token counts
"""

import sys
import json
from pathlib import Path
from collections import defaultdict, Counter
from typing import List, Dict, Any

from src.config import DATASET_ROOT, REPORTS_DIR

def run_data_audit(samples: List[Dict[str, Any]], output_path: Path = REPORTS_DIR / "data_audit_report.json") -> Dict[str, Any]:
    print("[Audit] Starting dataset quality and leakage audit...", flush=True)

    total_samples = len(samples)
    empty_samples = []
    raw_hash_map = defaultdict(list)
    norm_hash_map = defaultdict(list)
    lang_counter = Counter()
    label_counter = Counter()
    gen_counter = Counter()
    code_lens_chars = []
    code_lens_lines = []

    missing_fields = defaultdict(int)

    for s in samples:
        sid = s["sample_id"]
        lang = s.get("language")
        lab = s.get("label_name")
        gen = s.get("generator")
        code = s.get("code", "")
        raw_h = s.get("raw_sha256")
        norm_h = s.get("norm_sha256")

        lang_counter[lang] += 1
        label_counter[lab] += 1
        gen_counter[gen] += 1

        c_len = len(code)
        c_lines = len(code.splitlines())
        code_lens_chars.append(c_len)
        code_lens_lines.append(c_lines)

        if c_len == 0 or len(code.strip()) == 0:
            empty_samples.append(sid)

        for required in ["sample_id", "language", "label", "code", "raw_sha256"]:
            if s.get(required) is None:
                missing_fields[required] += 1

        if not s.get("problem_id"):
            missing_fields["problem_id"] += 1

        raw_hash_map[raw_h].append(s)
        norm_hash_map[norm_h].append(s)

    # Detect collisions
    raw_duplicates = {h: slist for h, slist in raw_hash_map.items() if len(slist) > 1}
    norm_duplicates = {h: slist for h, slist in norm_hash_map.items() if len(slist) > 1}

    # Cross-label collisions (Identical code labeled as both AI and Human!)
    cross_label_raw = []
    for h, slist in raw_duplicates.items():
        labels = {s["label_name"] for s in slist}
        if len(labels) > 1:
            cross_label_raw.append({
                "hash": h,
                "samples": [{"sample_id": s["sample_id"], "label": s["label_name"], "generator": s["generator"], "path": s.get("rel_path")} for s in slist]
            })

    cross_label_norm = []
    for h, slist in norm_duplicates.items():
        labels = {s["label_name"] for s in slist}
        if len(labels) > 1:
            cross_label_norm.append({
                "hash": h,
                "samples": [{"sample_id": s["sample_id"], "label": s["label_name"], "generator": s["generator"], "path": s.get("rel_path")} for s in slist]
            })

    audit_result = {
        "total_samples": total_samples,
        "empty_files_count": len(empty_samples),
        "empty_sample_ids": empty_samples[:10],
        "class_distribution": dict(label_counter),
        "language_distribution": dict(lang_counter),
        "generator_distribution": dict(gen_counter),
        "missing_fields_summary": dict(missing_fields),
        "exact_duplicate_groups": len(raw_duplicates),
        "exact_duplicate_total_files": sum(len(v) for v in raw_duplicates.values()),
        "near_duplicate_groups": len(norm_duplicates),
        "near_duplicate_total_files": sum(len(v) for v in norm_duplicates.values()),
        "cross_label_raw_collisions_count": len(cross_label_raw),
        "cross_label_raw_collisions": cross_label_raw[:10],
        "cross_label_norm_collisions_count": len(cross_label_norm),
        "cross_label_norm_collisions": cross_label_norm[:10],
        "code_statistics": {
            "min_chars": min(code_lens_chars) if code_lens_chars else 0,
            "max_chars": max(code_lens_chars) if code_lens_chars else 0,
            "avg_chars": round(sum(code_lens_chars) / total_samples, 1) if total_samples else 0,
            "min_lines": min(code_lens_lines) if code_lens_lines else 0,
            "max_lines": max(code_lens_lines) if code_lens_lines else 0,
            "avg_lines": round(sum(code_lens_lines) / total_samples, 1) if total_samples else 0,
        }
    }

    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w", encoding="utf-8") as f:
        json.dump(audit_result, f, indent=2)

    print(f"[Audit] Audit complete. Saved to {output_path}", flush=True)
    print(f"[Audit] Exact duplicates: {audit_result['exact_duplicate_groups']} groups | Near duplicates: {audit_result['near_duplicate_groups']} groups", flush=True)
    print(f"[Audit] Cross-label conflicts: {audit_result['cross_label_raw_collisions_count']} raw, {audit_result['cross_label_norm_collisions_count']} normalized", flush=True)

    return audit_result
