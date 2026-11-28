# problem title : Repeated DNA Sequences
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen = set()
        res = set()
        for i in range(len(s) - 9):
            sub = s[i:i + 10]
            if sub in seen:
                res.add(sub)
            seen.add(sub)
        return list(res)
