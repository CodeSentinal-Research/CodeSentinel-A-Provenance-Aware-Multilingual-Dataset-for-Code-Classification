# problem title : Letter Combinations of a Phone Number
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        phone = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        res = []

        def backtrack(idx: int, cur: str):
            if idx == len(digits):
                res.append(cur)
                return
            for char in phone[digits[idx]]:
                backtrack(idx + 1, cur + char)

        backtrack(0, "")
        return res
