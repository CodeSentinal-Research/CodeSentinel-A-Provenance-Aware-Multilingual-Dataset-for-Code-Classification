# problem title : Main and Secondary Diagonal Sum
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        total = 0
        for i in range(n):
            total += mat[i][i]
            if i != n - 1 - i:
                total += mat[i][n - 1 - i]
        return total
