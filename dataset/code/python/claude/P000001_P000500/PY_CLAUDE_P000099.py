
from typing import List

class Solution:
    def printFloydTriangle(self, n: int) -> List[List[int]]:
        res = []
        num = 1
        for i in range(1, n + 1):
            row = []
            for j in range(i):
                row.append(num)
                num += 1
            res.append(row)
        return res
