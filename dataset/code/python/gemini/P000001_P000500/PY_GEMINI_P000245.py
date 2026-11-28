from typing import List

class Solution:
    def lowerTriangular(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j] = 0
        return matrix