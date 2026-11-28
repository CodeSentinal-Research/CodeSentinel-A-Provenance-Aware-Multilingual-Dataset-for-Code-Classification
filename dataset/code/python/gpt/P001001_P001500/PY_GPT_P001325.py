# problem title : Combinations
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def backtrack(start: int, cur: List[int]):
            if len(cur) == k:
                res.append(list(cur))
                return
            for i in range(start, n + 1):
                cur.append(i)
                backtrack(i + 1, cur)
                cur.pop()

        backtrack(1, [])
        return res
