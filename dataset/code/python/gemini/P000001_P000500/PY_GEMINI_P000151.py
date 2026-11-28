from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        return max(nums[0] * nums[1], nums[-1] * nums[-2])