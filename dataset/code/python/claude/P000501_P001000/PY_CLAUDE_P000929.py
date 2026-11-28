
from typing import List

class Solution:
    def addMatrices(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]
