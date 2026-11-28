# problem title : Generate Generalized Abbreviations
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        res = []

        def backtrack(idx: int, cur: str, count: int):
            if idx == len(word):
                res.append(cur + (str(count) if count > 0 else ""))
                return
            # Option 1: abbreviate word[idx]
            backtrack(idx + 1, cur, count + 1)
            # Option 2: keep word[idx]
            backtrack(idx + 1, cur + (str(count) if count > 0 else "") + word[idx], 0)

        backtrack(0, "", 0)
        return res
