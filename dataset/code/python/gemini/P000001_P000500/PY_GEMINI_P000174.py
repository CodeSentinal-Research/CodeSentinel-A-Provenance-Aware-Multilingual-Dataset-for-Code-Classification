from typing import List

class Solution:
    def minDiff(self, arr: List[int]) -> int:
        arr.sort()
        min_diff = float('inf')
        for i in range(1, len(arr)):
            min_diff = min(min_diff, arr[i] - arr[i - 1])
        return min_diff