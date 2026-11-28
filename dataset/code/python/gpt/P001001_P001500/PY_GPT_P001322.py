# problem title : Combination Sum
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def backtrack(idx: int, cur: List[int], cur_sum: int):
            if cur_sum == target:
                res.append(list(cur))
                return
            if cur_sum > target or idx == len(candidates):
                return

            # Include candidates[idx]
            cur.append(candidates[idx])
            backtrack(idx, cur, cur_sum + candidates[idx])
            cur.pop()

            # Skip candidates[idx]
            backtrack(idx + 1, cur, cur_sum)

        backtrack(0, [], 0)
        return res
