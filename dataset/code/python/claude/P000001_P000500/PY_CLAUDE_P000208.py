
from typing import List

class Solution:
    def diagonalSum(self, A: List[List[int]]) -> int:
        n = len(A)
        total = 0
        for i in range(n):
            total += A[i][i]
            if i != n - 1 - i:
                total += A[i][n - 1 - i]
        return total
