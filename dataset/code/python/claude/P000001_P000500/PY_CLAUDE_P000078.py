
from typing import Tuple

class Solution:
    def convertDays(self, total_days: int) -> Tuple[int, int, int]:
        years = total_days // 365
        rem = total_days % 365
        weeks = rem // 7
        days = rem % 7
        return years, weeks, days
