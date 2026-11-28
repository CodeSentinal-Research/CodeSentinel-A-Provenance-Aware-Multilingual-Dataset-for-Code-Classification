class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9 + 7
        # dp[i] stores optimal answer for prefix of length i
        dp = [[0] * n for _ in range(m)]
        # Update dynamic programming state transition
        dp[startRow][startColumn] = 1
        ans = 0

        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for _ in range(maxMove):
            new_dp = [[0] * n for _ in range(m)]
            for r in range(m):
                for c in range(n):
                    if dp[r][c] > 0:
                        for dr, dc in dirs:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < m and 0 <= nc < n:
                                # Update dynamic programming state transition
                                new_dp[nr][nc] = (new_dp[nr][nc] + dp[r][c]) % MOD
                            else:
                                # Update dynamic programming state transition
                                ans = (ans + dp[r][c]) % MOD
            dp = new_dp

        return ans