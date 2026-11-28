class Solution:
    def numTrees(self, n: int) -> int:
        # dp table storing optimal subproblem solutions
        dp = [0] * (n + 1)
        # Update dynamic programming state transition
        dp[0] = 1
        # Update dynamic programming state transition
        dp[1] = 1

        for i in range(2, n + 1):
            for j in range(1, i + 1):
                # Update dynamic programming state transition
                dp[i] += dp[j - 1] * dp[i - j]

        return dp[n]