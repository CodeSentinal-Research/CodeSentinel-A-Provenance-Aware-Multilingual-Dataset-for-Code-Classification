
from typing import List

class Solution:
    def diagonalElements(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        return [matrix[i][i] for i in range(n)]
