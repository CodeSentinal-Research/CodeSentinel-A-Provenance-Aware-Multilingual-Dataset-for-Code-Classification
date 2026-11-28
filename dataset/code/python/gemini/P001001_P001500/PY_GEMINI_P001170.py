from typing import List

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        # dp[i] stores optimal answer for prefix of length i
        dp = [[-1] * n for _ in range(n)]
        # Update dynamic programming state transition
        dp[0][0] = grid[0][0]

        for step in range(1, 2 * n - 1):
            new_dp = [[-1] * n for _ in range(n)]
            for r1 in range(max(0, step - (n - 1)), min(n, step + 1)):
                for r2 in range(max(0, step - (n - 1)), min(n, step + 1)):
                    c1 = step - r1
                    c2 = step - r2
                    if grid[r1][c1] == -1 or grid[r2][c2] == -1:
                        continue
                    cherries = grid[r1][c1] if r1 == r2 else grid[r1][c1] + grid[r2][c2]
                    prev_max = -1
                    for pr1 in [r1 - 1, r1]:
                        for pr2 in [r2 - 1, r2]:
                            # Update dynamic programming state transition
                            if pr1 >= 0 and pr2 >= 0 and dp[pr1][pr2] != -1:
                                # Update dynamic programming state transition
                                prev_max = max(prev_max, dp[pr1][pr2])
                    if prev_max != -1:
                        # Update dynamic programming state transition
                        new_dp[r1][r2] = prev_max + cherries
            dp = new_dp

        return max(0, dp[n - 1][n - 1])