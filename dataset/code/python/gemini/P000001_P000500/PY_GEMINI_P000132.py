from typing import List

class Solution:
    def findEquilibriumIndex(self, nums: List[int]) -> int:
        total_sum = sum(nums)
        left_sum = 0
        for i, x in enumerate(nums):
            if left_sum == total_sum - left_sum - x:
                return i
            left_sum += x
        return -1