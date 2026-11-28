
from typing import List

class Solution:
    def largestSumIncreasing(self, nums: List[int]) -> int:
        if not nums: return 0
        best = cur = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                cur += nums[i]
            else:
                cur = nums[i]
            best = max(best, cur)
        return best
