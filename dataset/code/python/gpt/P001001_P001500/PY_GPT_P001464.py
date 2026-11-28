# problem title : Move Zeroes
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        insert_pos = 0
        for x in nums:
            if x != 0:
                nums[insert_pos] = x
                insert_pos += 1
        while insert_pos < len(nums):
            nums[insert_pos] = 0
            insert_pos += 1
