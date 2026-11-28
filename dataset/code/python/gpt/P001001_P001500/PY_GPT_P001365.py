# problem title : Gold Mine Path
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(r: int, c: int) -> int:
            if not (0 <= r < m and 0 <= c < n and grid[r][c] > 0):
                return 0
            gold = grid[r][c]
            grid[r][c] = 0

            max_sub = max(
                dfs(r + 1, c),
                dfs(r - 1, c),
                dfs(r, c + 1),
                dfs(r, c - 1)
            )

            grid[r][c] = gold
            return gold + max_sub

        return max((dfs(i, j) for i in range(m) for j in range(n) if grid[i][j] > 0), default=0)
