from typing import List

class Solution:
    def validStrings(self, n: int) -> List[str]:
        res = []

        def backtrack(cur: str):
            if len(cur) == n:
                res.append(cur)
                return
            backtrack(cur + "1")
            if not cur or cur[-1] != '0':
                backtrack(cur + "0")

        backtrack("")
        return res