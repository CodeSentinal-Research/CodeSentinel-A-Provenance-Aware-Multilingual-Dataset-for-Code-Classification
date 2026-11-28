# problem title : Combination Sum II
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def backtrack(idx: int, cur: List[int], cur_sum: int):
            if cur_sum == target:
                res.append(list(cur))
                return
            if cur_sum > target:
                return

            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue
                cur.append(candidates[i])
                backtrack(i + 1, cur, cur_sum + candidates[i])
                cur.pop()

        backtrack(0, [], 0)
        return res
