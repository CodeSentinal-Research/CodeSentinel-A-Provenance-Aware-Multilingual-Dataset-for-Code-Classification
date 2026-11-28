# problem title : Paint House
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0
        r, g, b = 0, 0, 0
        for cr, cg, cb in costs:
            nr = cr + min(g, b)
            ng = cg + min(r, b)
            nb = cb + min(r, g)
            r, g, b = nr, ng, nb
        return min(r, g, b)
