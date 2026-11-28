# problem title : Contains Duplicate
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
