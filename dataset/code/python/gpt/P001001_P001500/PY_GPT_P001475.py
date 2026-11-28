# problem title : Sort Colors
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        l, curr, r = 0, 0, len(nums) - 1
        while curr <= r:
            if nums[curr] == 0:
                nums[l], nums[curr] = nums[curr], nums[l]
                l += 1
                curr += 1
            elif nums[curr] == 2:
                nums[curr], nums[r] = nums[r], nums[curr]
                r -= 1
            else:
                curr += 1
