from typing import List

class Solution:
    def minProduct(self, nums: List[int]) -> int:
        nums.sort()
        return min(nums[0] * nums[-1], min(nums[0] * nums[1], nums[-1] * nums[-2]))