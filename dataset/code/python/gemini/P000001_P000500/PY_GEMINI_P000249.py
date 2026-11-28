from typing import List

class Solution:
    def multiplyMatrix(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        if len(A[0]) != len(B):
            return []
        r1, c1, c2 = len(A), len(A[0]), len(B[0])
        res = [[0] * c2 for _ in range(r1)]

        for i in range(r1):
            for j in range(c2):
                for k in range(c1):
                    res[i][j] += A[i][k] * B[k][j]

        return res