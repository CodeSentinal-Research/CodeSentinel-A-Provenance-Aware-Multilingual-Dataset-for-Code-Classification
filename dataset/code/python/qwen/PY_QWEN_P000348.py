n = int(input())
MOD = 10**9 + 7
dp = [[[0]*3 for _ in range(2)] for _ in range(n+1)]
dp[0][0][0] = 1
for i in range(1, n+1):
    for j in range(2):
        for k in range(3):
            dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD
            if j + 1 < 2:
                dp[i][j+1][0] = (dp[i][j+1][0] + dp[i-1][j][k]) % MOD
            if k + 1 < 3:
                dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % MOD
res = 0
for j in range(2):
    for k in range(3):
        res = (res + dp[n][j][k]) % MOD
print(res)
