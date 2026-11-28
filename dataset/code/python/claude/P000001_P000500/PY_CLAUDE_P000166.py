
from typing import List

class Solution:
    def minProductSubarray(self, nums: List[int]) -> int:
        best = cur_max = cur_min = nums[0]
        for x in nums[1:]:
            candidates = (x, cur_max*x, cur_min*x)
            cur_max = max(candidates)
            cur_min = min(candidates)
            best = min(best, cur_min)
        return best
