from typing import List

class Solution:
    def booleanMatrix(self, matrix: List[List[int]]) -> None:
        R, C = len(matrix), len(matrix[0])
        row_flag = [0] * R
        col_flag = [0] * C

        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 1:
                    row_flag[i] = 1
                    col_flag[j] = 1

        for i in range(R):
            for j in range(C):
                if row_flag[i] == 1 or col_flag[j] == 1:
                    matrix[i][j] = 1