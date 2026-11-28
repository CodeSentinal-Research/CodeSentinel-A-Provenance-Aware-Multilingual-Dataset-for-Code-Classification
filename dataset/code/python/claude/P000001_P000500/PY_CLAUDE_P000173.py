
from typing import List

class Solution:
    def maxDifference(self, nums: List[int]) -> int:
        min_val = nums[0]
        max_diff = float('-inf')
        for x in nums[1:]:
            max_diff = max(max_diff, x - min_val)
            min_val = min(min_val, x)
        return max_diff
