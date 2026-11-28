# problem title : Bitwise ORs of Subarrays
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res = set()
        cur = set()
        for x in arr:
            cur = {x | y for y in cur} | {x}
            res |= cur
        return len(res)
