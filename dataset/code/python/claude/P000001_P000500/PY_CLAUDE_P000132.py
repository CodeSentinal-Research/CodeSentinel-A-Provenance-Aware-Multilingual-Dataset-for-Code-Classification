
from typing import List

class Solution:
    def equilibriumIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        left_sum = 0
        for i, x in enumerate(nums):
            total -= x
            if left_sum == total:
                return i
            left_sum += x
        return -1
