from typing import List

class Solution:
    def determinantOfMatrix(self, matrix: List[List[int]], n: int) -> int:
        if n == 1:
            return matrix[0][0]
        if n == 2:
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

        det = 0
        for p in range(n):
            sub = []
            for i in range(1, n):
                sub_row = [matrix[i][j] for j in range(n) if j != p]
                sub.append(sub_row)
            sign = 1 if p % 2 == 0 else -1
            det += sign * matrix[0][p] * self.determinantOfMatrix(sub, n - 1)

        return det