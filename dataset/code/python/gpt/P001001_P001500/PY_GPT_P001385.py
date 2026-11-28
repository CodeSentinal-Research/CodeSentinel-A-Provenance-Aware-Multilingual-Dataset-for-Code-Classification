# problem title : Find All Missing Numbers
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for x in nums:
            idx = abs(x) - 1
            if nums[idx] > 0:
                nums[idx] = -nums[idx]

        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
