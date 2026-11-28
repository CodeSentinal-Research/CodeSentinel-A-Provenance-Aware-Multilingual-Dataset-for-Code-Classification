
from typing import List

class Solution:
    def longestDecreasingSubarray(self, nums: List[int]) -> int:
        if not nums: return 0
        best = cur = 1
        for i in range(1, len(nums)):
            cur = cur + 1 if nums[i] < nums[i-1] else 1
            best = max(best, cur)
        return best
