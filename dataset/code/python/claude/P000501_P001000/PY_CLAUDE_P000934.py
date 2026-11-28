
from typing import List

class Solution:
    def rotateMatrix(self, A: List[List[int]]) -> List[List[int]]:
        n = len(A)
        for i in range(n // 2):
            for j in range(i, n - 1 - i):
                temp = A[i][j]
                A[i][j] = A[n-1-j][i]
                A[n-1-j][i] = A[n-1-i][n-1-j]
                A[n-1-i][n-1-j] = A[j][n-1-i]
                A[j][n-1-i] = temp
        return A
