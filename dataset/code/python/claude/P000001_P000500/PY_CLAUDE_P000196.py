
from typing import List

class Solution:
    def largestSumK(self, nums: List[int], k: int) -> int:
        win = sum(nums[:k])
        best = win
        for i in range(k, len(nums)):
            win += nums[i] - nums[i-k]
            best = max(best, win)
        return best
