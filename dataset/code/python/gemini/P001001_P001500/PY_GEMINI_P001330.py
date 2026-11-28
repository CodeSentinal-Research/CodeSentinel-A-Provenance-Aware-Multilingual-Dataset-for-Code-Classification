from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        def backtrack(idx: int, cur: List[str]):
            if idx == len(s):
                res.append(list(cur))
                return
            for i in range(idx + 1, len(s) + 1):
                sub = s[idx:i]
                if sub == sub[::-1]:
                    cur.append(sub)
                    backtrack(i, cur)
                    cur.pop()

        backtrack(0, [])
        return res