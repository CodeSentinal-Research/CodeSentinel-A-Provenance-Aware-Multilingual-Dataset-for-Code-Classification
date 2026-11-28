
from typing import List

class Solution:
    def cyclicRotate(self, nums: List[int]) -> List[int]:
        if not nums: return nums
        return [nums[-1]] + nums[:-1]
