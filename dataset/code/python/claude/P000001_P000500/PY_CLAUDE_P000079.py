
from typing import Tuple

class Solution:
    def convertSeconds(self, total_seconds: int) -> Tuple[int, int, int]:
        hours = total_seconds // 3600
        rem = total_seconds % 3600
        minutes = rem // 60
        seconds = rem % 60
        return hours, minutes, seconds
