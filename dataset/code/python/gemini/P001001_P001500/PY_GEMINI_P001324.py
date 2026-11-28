from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []

        def backtrack(start: int, cur: List[int], cur_sum: int):
            if len(cur) == k:
                if cur_sum == n:
                    res.append(list(cur))
                return
            for i in range(start, 10):
                if cur_sum + i > n:
                    break
                cur.append(i)
                backtrack(i + 1, cur, cur_sum + i)
                cur.pop()

        backtrack(1, [], 0)
        return res