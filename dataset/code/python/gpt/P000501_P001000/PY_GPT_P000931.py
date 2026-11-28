# problem title : Matrix Transpose
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        r, c = len(matrix), len(matrix[0])
        return [[matrix[i][j] for i in range(r)] for j in range(c)]
