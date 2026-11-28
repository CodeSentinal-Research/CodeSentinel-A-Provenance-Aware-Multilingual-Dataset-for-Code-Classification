# problem title : Subsets
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(idx: int, cur: List[int]):
            if idx == len(nums):
                res.append(list(cur))
                return
            # Include nums[idx]
            cur.append(nums[idx])
            backtrack(idx + 1, cur)
            cur.pop()

            # Exclude nums[idx]
            backtrack(idx + 1, cur)

        backtrack(0, [])
        return res
