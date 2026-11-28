
from typing import List

class Solution:
    def sortMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        flat = sorted(x for row in matrix for x in row)
        idx = 0
        for i in range(m):
            for j in range(n):
                matrix[i][j] = flat[idx]; idx += 1
        return matrix
