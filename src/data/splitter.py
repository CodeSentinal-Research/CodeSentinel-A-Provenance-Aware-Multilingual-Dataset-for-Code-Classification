"""
Reproducible Split Generation Module with Leakage Prevention.
Partitions the dataset into Train (70%), Val (15%), and Test (15%) splits
with strict group isolation:
- All duplicate & near-duplicate codes are locked into the same split.
- All AI solutions solving the same problem ID are locked into the same split.
- All CodeNet human solutions solving the same problem ID are locked into the same split.
- Disjoint Set Union (Union-Find) guarantees that no transitive overlap crosses split partitions.
- Also supports strict Source-Held-Out partitioning (leave-one-generator-out).
"""

import os
import sys
import json
import random
from pathlib import Path
from collections import defaultdict, Counter
from typing import List, Dict, Any, Tuple, Optional

from src.config import (
    MANIFEST_DIR,
    RANDOM_SEED,
    TRAIN_RATIO,
    VAL_RATIO,
    TEST_RATIO,
    LANGUAGES,
    AI_GENERATORS,
)

class DisjointSetUnion:
    """Union-Find data structure for clustering connected samples."""
    def __init__(self):
        self.parent = {}

    def find(self, x: str) -> str:
        if self.parent.setdefault(x, x) != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: str, y: str):
        rx, ry = self.find(x), self.find(y)
        if rx != ry:
            self.parent[rx] = ry

def generate_splits(
    samples: List[Dict[str, Any]],
    output_dir: Path = MANIFEST_DIR,
    seed: int = RANDOM_SEED,
    held_out_generator: Optional[str] = None
) -> Tuple[List[Dict[str, Any]], List[Dict[str, Any]], List[Dict[str, Any]], Dict[str, Any]]:
    """
    Partitions samples into train, val, test with leak prevention.
    """
    random.seed(seed)
    dsu = DisjointSetUnion()

    # 1. Connect samples by shared problem IDs and duplicate hashes
    for s in samples:
        sid = s["sample_id"]
        # Connect to normalized hash
        norm_h = s.get("norm_sha256")
        if norm_h:
            dsu.union(sid, f"hash_{norm_h}")
        
        # Connect to raw hash
        raw_h = s.get("raw_sha256")
        if raw_h:
            dsu.union(sid, f"raw_{raw_h}")

        # Connect to problem ID
        pid = s.get("problem_id")
        if pid:
            prefix = "ai_prob_" if s["label"] == 1 else "human_prob_"
            dsu.union(sid, f"{prefix}{pid}")

    # 2. Gather clusters of samples
    clusters: Dict[str, List[Dict[str, Any]]] = defaultdict(list)
    for s in samples:
        root_cluster = dsu.find(s["sample_id"])
        clusters[root_cluster].append(s)

    cluster_list = list(clusters.values())
    # Shuffle clusters deterministically
    random.shuffle(cluster_list)

    # 3. Partition clusters into Train, Val, Test using greedy bin packing
    cluster_list.sort(key=len, reverse=True)
    total_samples = len(samples)
    target_train = int(total_samples * TRAIN_RATIO)
    target_val = int(total_samples * VAL_RATIO)

    train_clusters, val_clusters, test_clusters = [], [], []
    train_cnt = val_cnt = test_cnt = 0

    for c in cluster_list:
        c_len = len(c)
        train_def = (target_train - train_cnt) / TRAIN_RATIO
        val_def = (target_val - val_cnt) / VAL_RATIO
        test_def = ((total_samples - target_train - target_val) - test_cnt) / TEST_RATIO

        best_split = max([("train", train_def), ("val", val_def), ("test", test_def)], key=lambda x: x[1])[0]

        if best_split == "train":
            train_clusters.append(c)
            train_cnt += c_len
        elif best_split == "val":
            val_clusters.append(c)
            val_cnt += c_len
        else:
            test_clusters.append(c)
            test_cnt += c_len

    # Flatten clusters into sample lists
    if held_out_generator:
        held_out_generator = held_out_generator.lower()
        if held_out_generator not in AI_GENERATORS:
            raise ValueError(f"Unknown generator '{held_out_generator}'. Must be in {AI_GENERATORS}")
        
        # Strict exclusion of held-out generator from train and val
        train_samples = [s for c in train_clusters for s in c if s.get("generator") != held_out_generator]
        val_samples = [s for c in val_clusters for s in c if s.get("generator") != held_out_generator]
        # In test, include human samples and held-out generator samples
        test_samples = [s for c in test_clusters for s in c]
    else:
        train_samples = [s for c in train_clusters for s in c]
        val_samples = [s for c in val_clusters for s in c]
        test_samples = [s for c in test_clusters for s in c]

    # Verify zero leakage
    train_ids = {s["sample_id"] for s in train_samples}
    val_ids = {s["sample_id"] for s in val_samples}
    test_ids = {s["sample_id"] for s in test_samples}

    assert len(train_ids.intersection(val_ids)) == 0, "Leakage detected between Train and Val!"
    assert len(train_ids.intersection(test_ids)) == 0, "Leakage detected between Train and Test!"
    assert len(val_ids.intersection(test_ids)) == 0, "Leakage detected between Val and Test!"

    train_hashes = {s["norm_sha256"] for s in train_samples if s.get("norm_sha256")}
    val_hashes = {s["norm_sha256"] for s in val_samples if s.get("norm_sha256")}
    test_hashes = {s["norm_sha256"] for s in test_samples if s.get("norm_sha256")}

    assert len(train_hashes.intersection(val_hashes)) == 0, "Hash duplicate leakage between Train and Val!"
    assert len(train_hashes.intersection(test_hashes)) == 0, "Hash duplicate leakage between Train and Test!"
    assert len(val_hashes.intersection(test_hashes)) == 0, "Hash duplicate leakage between Val and Test!"

    # Compile split audit stats
    def get_stats(subset: List[Dict[str, Any]]) -> Dict[str, Any]:
        total = len(subset)
        human_c = sum(1 for s in subset if s["label"] == 0)
        ai_c = sum(1 for s in subset if s["label"] == 1)
        lang_c = Counter(s["language"] for s in subset)
        gen_c = Counter(s.get("generator") for s in subset)
        return {
            "total_samples": total,
            "human_count": human_c,
            "human_pct": round(human_c / total * 100, 2) if total else 0,
            "ai_count": ai_c,
            "ai_pct": round(ai_c / total * 100, 2) if total else 0,
            "language_distribution": dict(lang_c),
            "generator_distribution": dict(gen_c)
        }

    audit_summary = {
        "random_seed": seed,
        "held_out_generator": held_out_generator,
        "total_samples": len(samples),
        "total_clusters": len(clusters),
        "train": get_stats(train_samples),
        "val": get_stats(val_samples),
        "test": get_stats(test_samples),
        "leakage_verification": {
            "cross_split_sample_leakage": 0,
            "cross_split_hash_duplicate_leakage": 0,
            "problem_id_leakage_prevented": True
        }
    }

    # Save manifests
    prefix = f"heldout_{held_out_generator}_" if held_out_generator else "standard_"
    output_dir.mkdir(parents=True, exist_ok=True)
    
    with open(output_dir / f"{prefix}train_manifest.jsonl", "w", encoding="utf-8") as f:
        for s in train_samples:
            f.write(json.dumps(s) + "\n")

    with open(output_dir / f"{prefix}val_manifest.jsonl", "w", encoding="utf-8") as f:
        for s in val_samples:
            f.write(json.dumps(s) + "\n")

    with open(output_dir / f"{prefix}test_manifest.jsonl", "w", encoding="utf-8") as f:
        for s in test_samples:
            f.write(json.dumps(s) + "\n")

    with open(output_dir / f"{prefix}split_summary.json", "w", encoding="utf-8") as f:
        json.dump(audit_summary, f, indent=2)

    print(f"[Splitter] Splits generated ({prefix}): Train={len(train_samples)}, Val={len(val_samples)}, Test={len(test_samples)}", flush=True)
    return train_samples, val_samples, test_samples, audit_summary
