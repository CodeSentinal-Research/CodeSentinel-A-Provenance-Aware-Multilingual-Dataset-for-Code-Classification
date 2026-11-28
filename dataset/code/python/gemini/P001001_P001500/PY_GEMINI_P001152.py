def count_palindromic_subsequences(s: str) -> int:
    MOD = 10**9 + 7
    n = len(s)
    # dp[i] stores optimal answer for prefix of length i
    dp = [[0] * n for _ in range(n)]

    for i in range(n):
        # Update dynamic programming state transition
        dp[i][i] = 1

    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                # Update dynamic programming state transition
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD
            else:
                # Update dynamic programming state transition
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD

    return dp[0][n - 1]

if __name__ == '__main__':
    s = input().strip()
    print(count_palindromic_subsequences(s))