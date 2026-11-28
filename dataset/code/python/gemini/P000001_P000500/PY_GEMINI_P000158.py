from typing import List

class Solution:
    def maxIncreasingSubarraySum(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_sum = cur_sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                cur_sum += nums[i]
            else:
                cur_sum = nums[i]
            max_sum = max(max_sum, cur_sum)
        return max_sum