"""
Hardware Protection and Thermal Management Module.
Monitors training duration and enforces periodic cooldown pauses
to prevent thermal throttling and hardware degradation on laptop GPUs (e.g., RTX 3050).
"""

import time
import torch
from typing import Optional

class CooldownManager:
    """
    Tracks elapsed training time and triggers a sleep interval whenever
    the active training duration exceeds the configured threshold.
    """
    def __init__(
        self,
        interval_seconds: float = 300.0,  # 5 minutes
        cooldown_seconds: float = 30.0,   # 30 seconds
        enabled: bool = True,
        component_name: str = "Training"
    ):
        self.interval = interval_seconds
        self.cooldown = cooldown_seconds
        self.enabled = enabled
        self.component_name = component_name
        self.last_pause_time = time.time()
        self.total_paused_seconds = 0.0
        self.pause_count = 0

    def check(self, step_info: Optional[str] = None):
        """Checks if interval has elapsed since last cooldown. If so, pauses execution."""
        if not self.enabled or self.interval <= 0 or self.cooldown <= 0:
            return

        now = time.time()
        elapsed = now - self.last_pause_time
        if elapsed >= self.interval:
            self.pause_count += 1
            info_str = f" [{step_info}]" if step_info else ""
            print(
                f"\n[Hardware Protection] [COOLDOWN] {elapsed/60:.1f} minutes of continuous training reached{info_str}.\n"
                f"[Hardware Protection] [COOLDOWN] Initiating {self.cooldown:.0f}-second thermal cooldown for GPU/CPU protection...",
                flush=True
            )
            if torch.cuda.is_available():
                torch.cuda.empty_cache()

            t_sleep_start = time.time()
            time.sleep(self.cooldown)
            actual_sleep = time.time() - t_sleep_start
            self.total_paused_seconds += actual_sleep

            print(
                f"[Hardware Protection] [RESUMED] Cooldown complete ({actual_sleep:.1f}s rested). Resuming {self.component_name} at {time.strftime('%H:%M:%S')}.\n",
                flush=True
            )
            self.last_pause_time = time.time()
