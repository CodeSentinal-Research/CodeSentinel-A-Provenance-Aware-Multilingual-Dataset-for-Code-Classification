# problem title : Permutations
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(first: int):
            if first == len(nums):
                res.append(list(nums))
                return
            for i in range(first, len(nums)):
                nums[first], nums[i] = nums[i], nums[first]
                backtrack(first + 1)
                nums[first], nums[i] = nums[i], nums[first]

        backtrack(0)
        return res
