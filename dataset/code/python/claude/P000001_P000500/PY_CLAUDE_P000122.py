
from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = cur = nums[0]
        for x in nums[1:]:
            cur = max(x, cur + x)
            max_sum = max(max_sum, cur)
        return max_sum
