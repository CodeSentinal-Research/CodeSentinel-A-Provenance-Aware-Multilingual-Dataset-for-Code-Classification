from typing import List

class Solution:
    def activitySelection(self, start: List[int], end: List[int], n: int) -> int:
        activities = sorted(zip(start, end), key=lambda x: x[1])
        count = 0
        last_end = float('-inf')

        for s, e in activities:
            if s > last_end:
                count += 1
                last_end = e

        return count