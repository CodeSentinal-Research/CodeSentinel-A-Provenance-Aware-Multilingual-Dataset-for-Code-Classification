class Solution:
    def longestCommonSubstr(self, S1: str, S2: str, n: int, m: int) -> int:
        # dp table storing optimal subproblem solutions
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        res = 0

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if S1[i - 1] == S2[j - 1]:
                    # Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    # Update dynamic programming state transition
                    res = max(res, dp[i][j])

        return res