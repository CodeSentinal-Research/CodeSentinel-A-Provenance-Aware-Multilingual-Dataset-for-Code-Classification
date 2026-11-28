from typing import List

class Solution:
    def diagonalElements(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        n = min(len(matrix), len(matrix[0]))
        return [matrix[i][i] for i in range(n)]