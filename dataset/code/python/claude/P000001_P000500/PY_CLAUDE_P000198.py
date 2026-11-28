
from typing import List

class Solution:
    def containsContiguous(self, nums: List[int]) -> bool:
        if not nums: return True
        mn, mx = min(nums), max(nums)
        return mx - mn == len(nums) - 1 and len(set(nums)) == len(nums)
