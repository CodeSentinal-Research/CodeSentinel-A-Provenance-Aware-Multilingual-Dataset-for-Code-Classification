from typing import List

class Solution:
    def findSaddlePoint(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(n):
            min_row = matrix[i][0]
            col_idx = 0
            for j in range(1, n):
                if matrix[i][j] < min_row:
                    min_row = matrix[i][j]
                    col_idx = j

            is_saddle = True
            for k in range(n):
                if matrix[k][col_idx] > min_row:
                    is_saddle = False
                    break

            if is_saddle:
                return min_row
        return -1