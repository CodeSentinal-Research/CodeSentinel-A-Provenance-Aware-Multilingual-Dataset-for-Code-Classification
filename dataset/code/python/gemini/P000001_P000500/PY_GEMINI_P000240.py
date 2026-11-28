from typing import List

class Solution:
    def sumOfBoundaryElements(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        total = 0
        for i in range(n):
            for j in range(n):
                if i == 0 or j == 0 or i == n - 1 or j == n - 1:
                    total += matrix[i][j]
        return total