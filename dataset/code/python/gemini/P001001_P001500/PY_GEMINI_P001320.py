from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def backtrack(open_c: int, close_c: int, cur: str):
            if len(cur) == 2 * n:
                res.append(cur)
                return
            if open_c < n:
                backtrack(open_c + 1, close_c, cur + "(")
            if close_c < open_c:
                backtrack(open_c, close_c + 1, cur + ")")

        backtrack(0, 0, "")
        return res