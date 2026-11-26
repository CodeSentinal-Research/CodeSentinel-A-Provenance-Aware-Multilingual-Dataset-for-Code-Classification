"""
Configuration module for the Human vs AI Code Classification Research Pipeline.
Centralizes all experiment hyperparameters, file paths, seeds, and hardware settings.
"""

from dataclasses import dataclass, field
from pathlib import Path
from typing import List, Optional
import torch

# Base project root
PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATASET_ROOT = PROJECT_ROOT / "dataset" / "dataset"

# Output directories
OUTPUT_DIR = PROJECT_ROOT / "outputs"
DATA_PROCESSED_DIR = OUTPUT_DIR / "processed_data"
MANIFEST_DIR = OUTPUT_DIR / "splits"
CHECKPOINT_DIR = OUTPUT_DIR / "checkpoints"
METRICS_DIR = OUTPUT_DIR / "metrics"
FIGURES_DIR = OUTPUT_DIR / "figures"
REPORTS_DIR = OUTPUT_DIR / "reports"

for d in [DATA_PROCESSED_DIR, MANIFEST_DIR, CHECKPOINT_DIR, METRICS_DIR, FIGURES_DIR, REPORTS_DIR]:
    d.mkdir(parents=True, exist_ok=True)

RANDOM_SEED = 42

LANGUAGES: List[str] = ["c", "cpp", "java", "javascript", "python"]
AI_GENERATORS: List[str] = ["chatgpt", "deepseek", "gemini", "qwen"]
GENERATOR2ID = {g: i for i, g in enumerate(AI_GENERATORS)}
ID2GENERATOR = {i: g for i, g in enumerate(AI_GENERATORS)}
NUM_GENERATORS = len(AI_GENERATORS)

# Hardware detection
CUDA_AVAILABLE = torch.cuda.is_available()
DEVICE = "cuda" if CUDA_AVAILABLE else "cpu"
DEVICE_NAME = torch.cuda.get_device_name(0) if CUDA_AVAILABLE else "CPU"
VRAM_GB = (
    torch.cuda.get_device_properties(0).total_memory / (1024**3)
    if CUDA_AVAILABLE
    else 0.0
)

# Split ratios
TRAIN_RATIO = 0.70
VAL_RATIO = 0.15
TEST_RATIO = 0.15

@dataclass
class TfidfSvmConfig:
    char_ngram_range: tuple = (3, 5)
    word_ngram_range: tuple = (1, 2)
    max_char_features: int = 15000
    max_word_features: int = 15000
    c_param: float = 1.0
    random_state: int = RANDOM_SEED

@dataclass
class TfidfRfConfig:
    max_features: int = 10000
    n_estimators: int = 100
    max_depth: Optional[int] = 30
    n_jobs: int = -1
    random_state: int = RANDOM_SEED

@dataclass
class EmbeddingSvmConfig:
    model_name: str = "microsoft/unixcoder-base"
    batch_size: int = 32 if CUDA_AVAILABLE else 8
    max_length: int = 256
    pooling: str = "mean"
    c_param: float = 1.0
    random_state: int = RANDOM_SEED

# Hardware Protection & Cooldown Settings
COOLDOWN_INTERVAL_SECONDS: float = 300.0  # 5 minutes of training
COOLDOWN_DURATION_SECONDS: float = 30.0   # 30 seconds cooldown

@dataclass
class CodeT5Config:
    model_name: str = "Salesforce/codet5-small"  # Highly effective & fits smoothly in 6GB VRAM
    max_length: int = 256
    train_batch_size: int = 8
    eval_batch_size: int = 16
    gradient_accumulation_steps: int = 2  # Effective batch size = 16
    learning_rate: float = 3e-5
    num_train_epochs: int = 3
    weight_decay: float = 0.01
    warmup_ratio: float = 0.1
    fp16: bool = CUDA_AVAILABLE
    cooldown_interval: float = COOLDOWN_INTERVAL_SECONDS
    cooldown_duration: float = COOLDOWN_DURATION_SECONDS
    random_state: int = RANDOM_SEED

@dataclass
class CodeBERTaConfig:
    model_name: str = "huggingface/CodeBERTa-small-v1"
    max_length: int = 256
    train_batch_size: int = 16
    eval_batch_size: int = 32
    gradient_accumulation_steps: int = 1
    learning_rate: float = 2e-5
    num_train_epochs: int = 3
    weight_decay: float = 0.01
    warmup_ratio: float = 0.1
    fp16: bool = CUDA_AVAILABLE
    cooldown_interval: float = COOLDOWN_INTERVAL_SECONDS
    cooldown_duration: float = COOLDOWN_DURATION_SECONDS
    random_state: int = RANDOM_SEED

@dataclass
class MultiTaskConfig:
    model_name: str = "huggingface/CodeBERTa-small-v1"
    max_length: int = 256
    train_batch_size: int = 16
    eval_batch_size: int = 32
    gradient_accumulation_steps: int = 1
    learning_rate: float = 2e-5
    num_train_epochs: int = 3
    weight_decay: float = 0.01
    warmup_ratio: float = 0.1
    task_a_weight: float = 1.0
    task_b_weight: float = 1.0
    fp16: bool = CUDA_AVAILABLE
    cooldown_interval: float = COOLDOWN_INTERVAL_SECONDS
    cooldown_duration: float = COOLDOWN_DURATION_SECONDS
    random_state: int = RANDOM_SEED


