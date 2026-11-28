from typing import List

class Solution:
    def sumMatrix(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        if len(A) != len(B) or len(A[0]) != len(B[0]):
            return []
        return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]