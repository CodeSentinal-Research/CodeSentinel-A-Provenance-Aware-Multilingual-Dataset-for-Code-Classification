
from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> List[int]:
        k = 0
        for x in nums:
            if x != 0:
                nums[k] = x
                k += 1
        while k < len(nums):
            nums[k] = 0
            k += 1
        return nums
