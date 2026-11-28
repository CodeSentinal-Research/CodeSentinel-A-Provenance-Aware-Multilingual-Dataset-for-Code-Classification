class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        # dp[i] stores optimal answer for prefix of length i
        dp = [0] * (k + 1)
        m = 0
        while dp[k] < n:
            m += 1
            for i in range(k, 0, -1):
                # Update dynamic programming state transition
                dp[i] = dp[i] + dp[i - 1] + 1
        return m