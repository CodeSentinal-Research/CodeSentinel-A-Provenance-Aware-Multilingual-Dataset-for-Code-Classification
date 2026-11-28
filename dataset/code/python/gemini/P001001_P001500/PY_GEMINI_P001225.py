class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7
        if n <= 2:
            return n
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * (n + 1)
        # Update dynamic programming state transition
        dp[0], dp[1], dp[2] = 1, 1, 2
        for i in range(3, n + 1):
            # Update dynamic programming state transition
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD
        return dp[n]