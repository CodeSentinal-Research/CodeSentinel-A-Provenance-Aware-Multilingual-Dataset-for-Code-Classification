# problem title : Minimum Number of Taps to Water a Garden
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        max_reach = [0] * (n + 1)
        for i, r in enumerate(ranges):
            left = max(0, i - r)
            right = min(n, i + r)
            max_reach[left] = max(max_reach[left], right)

        taps = 0
        cur_end = 0
        next_end = 0

        for i in range(n):
            next_end = max(next_end, max_reach[i])
            if i == cur_end:
                if next_end <= i:
                    return -1
                taps += 1
                cur_end = next_end

        return taps
