# problem title : Find Unique Paths III
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        empty = 0
        start_r = start_c = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    start_r, start_c = i, j
                elif grid[i][j] == 0:
                    empty += 1

        def dfs(r: int, c: int, count: int) -> int:
            if not (0 <= r < m and 0 <= c < n and grid[r][c] >= 0):
                return 0
            if grid[r][c] == 2:
                return 1 if count == empty + 1 else 0

            temp = grid[r][c]
            grid[r][c] = -2

            paths = (
                dfs(r + 1, c, count + 1) +
                dfs(r - 1, c, count + 1) +
                dfs(r, c + 1, count + 1) +
                dfs(r, c - 1, count + 1)
            )

            grid[r][c] = temp
            return paths

        return dfs(start_r, start_c, 0)
