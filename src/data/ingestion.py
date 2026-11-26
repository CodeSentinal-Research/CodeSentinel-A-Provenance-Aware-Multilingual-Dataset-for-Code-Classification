"""
Dataset Ingestion and Normalization Module (High-Performance).
Loads code files and heterogeneous metadata across 5 programming languages
and 4 AI generators, producing a standardized, unified schema while preserving
all available provenance, problem IDs, and generation metadata.
"""

import os
import sys
import json
import csv
import hashlib
import re
from pathlib import Path
from typing import Dict, Any, List, Optional, Tuple, Iterator
from collections import defaultdict

from src.config import DATASET_ROOT, DATA_PROCESSED_DIR, LANGUAGES, AI_GENERATORS

RE_PROBLEM_ID = re.compile(r"P\d{6}", re.IGNORECASE)

def compute_hashes(code: str) -> Tuple[str, str]:
    """Computes raw and whitespace-normalized SHA-256 hashes for code deduplication."""
    if isinstance(code, str):
        raw_bytes = code.encode("utf-8")
    else:
        raw_bytes = code
    raw_h = hashlib.sha256(raw_bytes).hexdigest()
    norm_bytes = b" ".join(raw_bytes.split())
    norm_h = hashlib.sha256(norm_bytes).hexdigest()
    return raw_h, norm_h


class MetadataCatalog:
    """Catalogs and provides O(1) lookup for all heterogeneous metadata in the repository."""

    def __init__(self, root: Path = DATASET_ROOT):
        self.root = root
        # Maps (lang, generator) -> {prob_id_upper: dict}
        self.ai_csv_map: Dict[Tuple[str, str], Dict[str, Dict[str, Any]]] = defaultdict(dict)
        self.human_records: Dict[str, Dict[str, Any]] = {}
        self._load_ai_csvs()
        self._load_human_metadata()

    def _load_ai_csvs(self):
        for csv_path in self.root.rglob("*.csv"):
            cname = csv_path.name.lower()
            # Determine lang and gen from filename or path
            detected_lang = None
            for l in LANGUAGES:
                if l in cname:
                    detected_lang = l
                    break
            detected_gen = None
            for g in AI_GENERATORS:
                if g in cname:
                    detected_gen = g
                    break
            if not detected_lang:
                detected_lang = csv_path.parts[-4] if len(csv_path.parts) >= 4 else "unknown"
            if not detected_gen:
                detected_gen = csv_path.parts[-2] if len(csv_path.parts) >= 2 else "unknown"

            try:
                with open(csv_path, "r", encoding="utf-8", errors="replace") as f:
                    reader = csv.DictReader(f)
                    for row in reader:
                        pid = row.get("id") or row.get("problemId") or row.get("problem_id")
                        if pid:
                            self.ai_csv_map[(detected_lang, detected_gen)][pid.upper()] = row
            except Exception as e:
                print(f"[Warning] Failed loading CSV {csv_path}: {e}", file=sys.stderr)

    def _load_human_metadata(self):
        # 1. JSONL files
        for jf in self.root.rglob("*.jsonl"):
            try:
                with open(jf, "r", encoding="utf-8", errors="replace") as f:
                    for line in f:
                        if not line.strip():
                            continue
                        try:
                            row = json.loads(line)
                        except Exception:
                            continue
                        fname = row.get("filename") or row.get("final_filename") or row.get("file")
                        fid = row.get("id") or row.get("human_id") or row.get("submission_id")
                        if fname:
                            self.human_records[fname] = row
                        if fid:
                            self.human_records[fid] = row
            except Exception as e:
                print(f"[Warning] Failed loading JSONL {jf}: {e}", file=sys.stderr)

        # 2. Extensionless metadata files (e.g., java_final_metadata)
        java_meta = self.root / "java" / "human" / "java_final_metadata"
        if java_meta.exists():
            try:
                with open(java_meta, "r", encoding="utf-8", errors="replace") as f:
                    for line in f:
                        if not line.strip(): continue
                        try:
                            row = json.loads(line)
                            fname = row.get("human_filename") or row.get("filename")
                            fid = row.get("human_id") or row.get("id")
                            if fname: self.human_records[fname] = row
                            if fid: self.human_records[fid] = row
                        except Exception:
                            continue
            except Exception as e:
                print(f"[Warning] Failed loading {java_meta}: {e}", file=sys.stderr)

    def lookup_csv_ai(self, lang: str, generator: str, problem_id: Optional[str]) -> Dict[str, Any]:
        if not problem_id:
            return {}
        pid_upper = problem_id.upper()
        # Direct lookup
        row = self.ai_csv_map.get((lang, generator), {}).get(pid_upper)
        if row:
            return {
                "problem_title": row.get("title"),
                "problem_category": row.get("category"),
                "difficulty": row.get("difficulty"),
                "raw_meta": row
            }
        # Fallback search
        for (l, g), tbl in self.ai_csv_map.items():
            if pid_upper in tbl:
                r = tbl[pid_upper]
                return {
                    "problem_title": r.get("title"),
                    "problem_category": r.get("category"),
                    "difficulty": r.get("difficulty"),
                    "raw_meta": r
                }
        return {}

    def lookup_human(self, filename: str) -> Dict[str, Any]:
        return self.human_records.get(filename, {})

def scan_dataset(root: Path = DATASET_ROOT) -> Iterator[Dict[str, Any]]:
    catalog = MetadataCatalog(root)

    for lang in sorted(LANGUAGES):
        lang_dir = root / lang
        if not lang_dir.exists():
            continue

        for sub in ["human", "ai"]:
            sub_dir = lang_dir / sub
            if not sub_dir.exists():
                continue

            target_dirs = []
            if sub == "ai":
                for gen_dir in sorted(sub_dir.iterdir()):
                    if gen_dir.is_dir() and gen_dir.name in AI_GENERATORS:
                        target_dirs.append((gen_dir.name, gen_dir))
            else:
                target_dirs.append(("human", sub_dir))

            for gen_name, dpath in target_dirs:
                # First pass: pre-read any .meta.json files in this folder in RAM
                folder_meta_jsons = {}
                code_entries = []

                for entry in os.scandir(dpath):
                    if not entry.is_file():
                        continue
                    name = entry.name
                    if name.endswith(".meta.json"):
                        stem = name[:-10] # remove .meta.json
                        try:
                            with open(entry.path, "r", encoding="utf-8", errors="replace") as f:
                                folder_meta_jsons[stem] = json.load(f)
                        except Exception:
                            pass
                    elif name.endswith((".csv", ".jsonl", ".json", ".txt", ".md")) or name in ["java_final_metadata", "js_final_metadata"]:
                        continue
                    else:
                        code_entries.append(entry)

                # Process all code files in this folder
                is_ai = (sub == "ai")
                label = 1 if is_ai else 0

                for entry in code_entries:
                    name = entry.name
                    try:
                        with open(entry.path, "rb") as fb:
                            raw_bytes = fb.read()
                        code_text = raw_bytes.decode("utf-8", errors="replace")
                    except Exception as e:
                        print(f"[Warning] Failed reading {entry.path}: {e}", file=sys.stderr)
                        continue

                    # Fast hashing
                    raw_h = hashlib.sha256(raw_bytes).hexdigest()
                    norm_bytes = b" ".join(raw_bytes.split())
                    norm_h = hashlib.sha256(norm_bytes).hexdigest()

                    meta_info = {}
                    prob_id = None

                    if is_ai:
                        m = RE_PROBLEM_ID.search(name)
                        prob_id = m.group(0).upper() if m else None

                        stem = Path(name).stem
                        if stem in folder_meta_jsons:
                            d = folder_meta_jsons[stem]
                            prob = d.get("problem", {})
                            meta_info = {
                                "problem_title": prob.get("title") if isinstance(prob, dict) else None,
                                "problem_category": prob.get("category") if isinstance(prob, dict) else None,
                                "difficulty": prob.get("difficulty") if isinstance(prob, dict) else None,
                                "problem_statement": prob.get("problemStatement") if isinstance(prob, dict) else None,
                                "provenance": d.get("provenance", {}),
                                "raw_meta": d
                            }
                        else:
                            meta_info = catalog.lookup_csv_ai(lang, gen_name, prob_id)
                    else:
                        meta_info = catalog.lookup_human(name)
                        raw_pid = meta_info.get("problem_id")
                        prob_id = str(raw_pid).strip() if raw_pid else None

                    rel_path = f"{lang}/{sub}/{gen_name}/{name}" if is_ai else f"{lang}/{sub}/{name}"

                    record = {
                        "sample_id": f"{lang}_{sub}_{gen_name}_{Path(name).stem}",
                        "filename": name,
                        "rel_path": rel_path,
                        "language": lang,
                        "label": label,
                        "label_name": "ai" if is_ai else "human",
                        "generator": gen_name,
                        "problem_id": prob_id,
                        "code": code_text,
                        "code_len_chars": len(code_text),
                        "code_len_lines": len(code_text.splitlines()),
                        "raw_sha256": raw_h,
                        "norm_sha256": norm_h,
                        "title": meta_info.get("problem_title") or meta_info.get("title"),
                        "category": meta_info.get("problem_category") or meta_info.get("topic_tags"),
                        "difficulty": meta_info.get("difficulty"),
                        "source_origin": meta_info.get("source") or ("OpenAI/DeepSeek/Gemini/Qwen" if is_ai else "GitHub/CodeNet"),
                        "metadata": meta_info
                    }
                    yield record

def build_normalized_dataset(output_path: Path = DATA_PROCESSED_DIR / "normalized_dataset.jsonl") -> int:
    output_path.parent.mkdir(parents=True, exist_ok=True)
    count = 0
    with open(output_path, "w", encoding="utf-8") as out_f:
        for record in scan_dataset():
            out_f.write(json.dumps(record) + "\n")
            count += 1
            if count % 10000 == 0:
                print(f"[Ingestion] Processed and saved {count} samples...", flush=True)

    print(f"[Ingestion] Completed normalization of {count} samples -> {output_path}", flush=True)
    return count

if __name__ == "__main__":
    build_normalized_dataset()
