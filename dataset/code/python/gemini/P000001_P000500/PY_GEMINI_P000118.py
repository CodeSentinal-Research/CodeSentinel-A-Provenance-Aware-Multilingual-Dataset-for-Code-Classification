from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        idx = 0
        for x in nums:
            if x != 0:
                nums[idx] = x
                idx += 1
        while idx < len(nums):
            nums[idx] = 0
            idx += 1