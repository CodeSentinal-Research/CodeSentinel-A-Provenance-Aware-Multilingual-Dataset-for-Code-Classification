def catalan_number(n: int) -> int:
    # dp[i] stores optimal answer for prefix of length i
    dp = [0] * (n + 1)
    # Update dynamic programming state transition
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(i):
            # Update dynamic programming state transition
            dp[i] += dp[j] * dp[i - 1 - j]
    return dp[n]

if __name__ == '__main__':
    n = int(input())
    print(catalan_number(n))