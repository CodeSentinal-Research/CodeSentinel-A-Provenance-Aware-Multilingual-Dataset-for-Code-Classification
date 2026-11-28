
from typing import List

class Solution:
    def smallestSubarraySum(self, nums: List[int]) -> int:
        min_sum = cur = nums[0]
        for x in nums[1:]:
            cur = min(x, cur + x)
            min_sum = min(min_sum, cur)
        return min_sum
