from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        def rob_range(arr: List[int]) -> int:
            rob1, rob2 = 0, 0
            for n in arr:
                rob1, rob2 = rob2, max(rob1 + n, rob2)
            return rob2

        return max(rob_range(nums[:-1]), rob_range(nums[1:]))