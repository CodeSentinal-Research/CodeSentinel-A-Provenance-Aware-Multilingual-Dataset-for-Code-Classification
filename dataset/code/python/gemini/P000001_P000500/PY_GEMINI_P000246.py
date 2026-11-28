from typing import List

class Solution:
    def upperTriangular(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        for i in range(n):
            for j in range(i):
                matrix[i][j] = 0
        return matrix