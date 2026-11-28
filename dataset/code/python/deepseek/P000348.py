Here is the Python code:

def solve(n):
    MOD = 10**9+7
    dp = [[0]*(n+1) for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n+1):
        dp[i][0] = dp[i-1][0]
        for j in range(1, i+1):
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD
            if j < i:
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD
    res = 0
    for i in range(1, n//2+1):
        res = (res + dp[n][i]) % MOD
    res = (res * 2) % MOD
    if n % 2 == 1:
        res = (res + dp[n][n//2+1]) % MOD
    return res

print(solve(int(input())))

In this code, we first initialize a 2D dynamic programming array `dp` of size `(n+1) x (n+1)`, where `dp[i][j]` represents the number of possible records of length `i` that end with `j` valid students. Then we fill the array based on the transition rules. Finally, we calculate the result based on the dynamic programming array.