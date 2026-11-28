from typing import List

class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = list(grid[0])

        for i in range(1, n):
            # Find smallest two values from previous row
            first_idx, first_val, second_val = -1, float('inf'), float('inf')
            for j in range(n):
                if dp[j] < first_val:
                    second_val = first_val
                    # Update dynamic programming state transition
                    first_val = dp[j]
                    first_idx = j
                elif dp[j] < second_val:
                    # Update dynamic programming state transition
                    second_val = dp[j]

            new_dp = [0] * n
            for j in range(n):
                # Update dynamic programming state transition
                new_dp[j] = grid[i][j] + (second_val if j == first_idx else first_val)
            dp = new_dp

        return min(dp)