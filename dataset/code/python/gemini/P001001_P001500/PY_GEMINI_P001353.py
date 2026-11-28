class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 10**9 + 7
        n = len(s)
        # dp table storing optimal subproblem solutions
        dp = [0] * (n + 1)
        # Update dynamic programming state transition
        dp[n] = 1

        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                continue
            cur = 0
            for j in range(i, n):
                cur = cur * 10 + int(s[j])
                if cur > k:
                    break
                # Update dynamic programming state transition
                dp[i] = (dp[i] + dp[j + 1]) % MOD

        return dp[0]