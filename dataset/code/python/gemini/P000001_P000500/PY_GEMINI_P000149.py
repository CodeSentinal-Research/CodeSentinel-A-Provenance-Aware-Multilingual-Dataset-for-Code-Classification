from typing import List

class Solution:
    def rowWithMax1s(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return -1
        m, n = len(matrix), len(matrix[0])
        r, c = 0, n - 1
        max_row = -1

        while r < m and c >= 0:
            if matrix[r][c] == 1:
                max_row = r
                c -= 1
            else:
                r += 1

        return max_row