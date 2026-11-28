# problem title : DI String Match
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        lo, hi = 0, len(s)
        res = []
        for c in s:
            if c == 'I':
                res.append(lo)
                lo += 1
            else:
                res.append(hi)
                hi -= 1
        res.append(lo)
        return res
