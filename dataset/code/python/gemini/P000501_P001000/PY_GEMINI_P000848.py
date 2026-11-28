from typing import List
import math

class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        ans = 0
        total = 0
        for i, x in enumerate(nums):
            total += x
            ans = max(ans, math.ceil(total / (i + 1)))
        return ans