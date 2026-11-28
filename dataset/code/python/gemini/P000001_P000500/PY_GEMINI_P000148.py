from typing import List

class Solution:
    def isSymmetric(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                if matrix[i][j] != matrix[j][i]:
                    return False
        return True