# problem title : Keyboard Row
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1, row2, row3 = set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")
        res = []
        for w in words:
            w_set = set(w.lower())
            if w_set <= row1 or w_set <= row2 or w_set <= row3:
                res.append(w)
        return res
