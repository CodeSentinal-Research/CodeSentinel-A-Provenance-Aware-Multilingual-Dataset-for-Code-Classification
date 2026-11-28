from typing import List

class Solution:
    def equilibriumPoint(self, arr: List[int]) -> int:
        total_sum = sum(arr)
        left_sum = 0
        for i, x in enumerate(arr):
            if left_sum == total_sum - left_sum - x:
                return i + 1
            left_sum += x
        return -1