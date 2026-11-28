from typing import List

class Solution:
    def printZigZag(self, matrix: List[List[int]]) -> List[int]:
        res = []
        for i, row in enumerate(matrix):
            if i % 2 == 0:
                res.extend(row)
            else:
                res.extend(reversed(row))
        return res