from typing import List

class Solution:
    def rotateMatrix(self, M: int, N: int, mat: List[List[int]]) -> List[List[int]]:
        row = 0
        col = 0
        m, n = M, N

        while row < m and col < n:
            if row + 1 == m or col + 1 == n:
                break

            prev = mat[row + 1][col]

            for i in range(col, n):
                curr = mat[row][i]
                mat[row][i] = prev
                prev = curr
            row += 1

            for i in range(row, m):
                curr = mat[i][n - 1]
                mat[i][n - 1] = prev
                prev = curr
            n -= 1

            if row < m:
                for i in range(n - 1, col - 1, -1):
                    curr = mat[m - 1][i]
                    mat[m - 1][i] = prev
                    prev = curr
                m -= 1

            if col < n:
                for i in range(m - 1, row - 1, -1):
                    curr = mat[i][col]
                    mat[i][col] = prev
                    prev = curr
                col += 1

        return mat