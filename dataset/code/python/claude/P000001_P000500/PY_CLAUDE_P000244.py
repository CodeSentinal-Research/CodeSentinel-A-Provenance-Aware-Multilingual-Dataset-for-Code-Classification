
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
dp = [row[:] for row in A]
for i in range(1, r):
    for j in range(c):
        opts = [dp[i-1][j]]
        if j>0: opts.append(dp[i-1][j-1])
        if j<c-1: opts.append(dp[i-1][j+1])
        dp[i][j] += max(opts)
print(max(dp[r-1]))
