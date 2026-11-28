from typing import List

class Solution:
    def BoundaryElements(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        res = []
        for i in range(n):
            for j in range(n):
                if i == 0 or j == 0 or i == n - 1 or j == n - 1:
                    res.append(matrix[i][j])
        return res