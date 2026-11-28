from typing import List

class Solution:
    def findMinDiff(self, a: List[int], n: int, m: int) -> int:
        if m == 0 or n == 0 or m > n:
            return 0
        a.sort()
        min_diff = float('inf')
        for i in range(n - m + 1):
            min_diff = min(min_diff, a[i + m - 1] - a[i])
        return min_diff