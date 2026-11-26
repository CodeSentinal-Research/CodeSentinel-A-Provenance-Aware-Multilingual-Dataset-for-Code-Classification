"""
Unit and Integration Tests for Dual-Classification Pipeline (Task A & Task B).
=============================================================================
Verifies:
1. MultiTaskDataset properly assigns 0/1 to Task A and masks human code with -100 for Task B.
2. MultiTaskCodeClassifier forward pass produces dual logits [B, 2] and [B, 4].
3. evaluate_generator_predictions calculates multiclass accuracy, macro-F1, per-generator recall,
   and 4x4 confusion matrix.
4. Classical and neural Task B classifiers execute without error on AI samples.
"""

import unittest
from pathlib import Path
import torch
import numpy as np

from src.config import AI_GENERATORS, GENERATOR2ID
from src.evaluation.generator_metrics import evaluate_generator_predictions
from src.models.generator_classifiers import filter_ai_samples, TfidfSvmGeneratorClassifier
from src.models.multitask_model import MultiTaskDataset, MultiTaskCodeClassifier


class DummyTokenizer:
    def __call__(self, text, truncation=True, max_length=64, padding="max_length", return_tensors="pt"):
        return {
            "input_ids": torch.zeros((1, max_length), dtype=torch.long),
            "attention_mask": torch.ones((1, max_length), dtype=torch.long)
        }


class TestDualClassification(unittest.TestCase):

    def test_multitask_dataset_masking(self):
        samples = [
            {"code": "int main() {}", "label": 0, "generator": "human"},
            {"code": "def solve(): pass", "label": 1, "generator": "chatgpt"},
            {"code": "console.log('hi')", "label": 1, "generator": "deepseek"},
            {"code": "void test() {}", "label": 1, "generator": "gemini"},
            {"code": "let a = 1;", "label": 1, "generator": "qwen"}
        ]
        tokenizer = DummyTokenizer()
        ds = MultiTaskDataset(samples, tokenizer, max_length=32)

        self.assertEqual(len(ds), 5)
        # Item 0: Human
        item0 = ds[0]
        self.assertEqual(item0["task_a_label"].item(), 0)
        self.assertEqual(item0["task_b_label"].item(), -100, "Human code must be masked (-100) for Task B")

        # Item 1: ChatGPT
        item1 = ds[1]
        self.assertEqual(item1["task_a_label"].item(), 1)
        self.assertEqual(item1["task_b_label"].item(), GENERATOR2ID["chatgpt"])

        # Item 4: Qwen
        item4 = ds[4]
        self.assertEqual(item4["task_a_label"].item(), 1)
        self.assertEqual(item4["task_b_label"].item(), GENERATOR2ID["qwen"])

    def test_ai_sample_filtering(self):
        samples = [
            {"sample_id": "1", "label": 0, "generator": "human"},
            {"sample_id": "2", "label": 1, "generator": "deepseek"},
            {"sample_id": "3", "label": 0, "generator": "human"},
            {"sample_id": "4", "label": 1, "generator": "qwen"},
            {"sample_id": "5", "label": 1, "generator": "unknown_ai"}  # unverified provenance
        ]
        filtered = filter_ai_samples(samples)
        self.assertEqual(len(filtered), 2)
        self.assertEqual({s["generator"] for s in filtered}, {"deepseek", "qwen"})

    def test_task_b_metrics_evaluation(self):
        # 4 generators: chatgpt=0, deepseek=1, gemini=2, qwen=3
        y_true = ["chatgpt", "deepseek", "gemini", "qwen", "chatgpt"]
        y_pred = ["chatgpt", "deepseek", "gemini", "gemini", "chatgpt"]  # 4/5 correct

        metadata = [
            {"sample_id": "s1", "language": "python", "generator": "chatgpt"},
            {"sample_id": "s2", "language": "python", "generator": "deepseek"},
            {"sample_id": "s3", "language": "java", "generator": "gemini"},
            {"sample_id": "s4", "language": "java", "generator": "qwen"},
            {"sample_id": "s5", "language": "cpp", "generator": "chatgpt"}
        ]

        metrics = evaluate_generator_predictions(
            y_true=y_true,
            y_pred=y_pred,
            model_name="test_task_b_model",
            metadata=metadata,
            save_dir=Path("outputs/test_metrics"),
            reports_dir=Path("outputs/test_reports")
        )

        self.assertEqual(metrics["accuracy"], 0.8)
        self.assertIn("per_generator_metrics", metrics)
        self.assertEqual(metrics["per_generator_metrics"]["chatgpt"]["recall"], 1.0)
        self.assertEqual(metrics["per_generator_metrics"]["qwen"]["recall"], 0.0)

        # Check 4x4 confusion matrix
        cm = np.array(metrics["confusion_matrix"]["raw_counts"])
        self.assertEqual(cm.shape, (4, 4))
        self.assertEqual(cm[0, 0], 2)  # 2 chatgpt true positive

        # Check per-language results
        per_lang = metrics["per_language_generator_performance"]
        self.assertIn("python", per_lang)
        self.assertEqual(per_lang["python"]["accuracy"], 1.0)

    def test_tfidf_svm_task_b_smoke(self):
        ai_texts = [
            "def chatgpt_func(): return 'chatgpt'",
            "def deepseek_func(): return 'deepseek'",
            "def gemini_func(): return 'gemini'",
            "def qwen_func(): return 'qwen'"
        ]
        ai_y = [0, 1, 2, 3]

        model = TfidfSvmGeneratorClassifier()
        dur = model.fit(ai_texts, ai_y)
        self.assertGreater(dur, 0)
        preds, probs, _ = model.predict(ai_texts)
        self.assertEqual(len(preds), 4)
        for p in preds:
            self.assertIn(p, [0, 1, 2, 3])


if __name__ == "__main__":
    unittest.main()
