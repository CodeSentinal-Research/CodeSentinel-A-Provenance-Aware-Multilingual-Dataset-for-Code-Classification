from typing import List

class Solution:
    def smallestSumSubarray(self, nums: List[int]) -> int:
        min_sum = cur_sum = nums[0]
        for x in nums[1:]:
            cur_sum = min(x, cur_sum + x)
            min_sum = min(min_sum, cur_sum)
        return min_sum