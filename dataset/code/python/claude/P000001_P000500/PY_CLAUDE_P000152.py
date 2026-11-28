
from typing import List

class Solution:
    def minProduct(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        candidates = [nums[0]*nums[1], nums[0]*nums[n-1], nums[n-2]*nums[n-1], nums[n-1]*nums[0]]
        return min(candidates)
