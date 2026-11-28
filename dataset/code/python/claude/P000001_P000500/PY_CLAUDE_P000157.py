
from typing import List

class Solution:
    def findEquilibrium(self, nums: List[int]) -> int:
        total = sum(nums)
        left = 0
        for i, x in enumerate(nums):
            total -= x
            if left == total:
                return i
            left += x
        return -1
