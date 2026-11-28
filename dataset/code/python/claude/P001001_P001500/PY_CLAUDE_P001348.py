
from typing import List

class Solution:
    def multiply(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        r1, c1, c2 = len(A), len(A[0]), len(B[0])
        C = [[0] * c2 for _ in range(r1)]
        for i in range(r1):
            for j in range(c2):
                for k in range(c1):
                    C[i][j] += A[i][k] * B[k][j]
        return C
