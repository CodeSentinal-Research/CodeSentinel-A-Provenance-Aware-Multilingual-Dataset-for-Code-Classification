# problem title : Maximum Size Square Submatrix
# Dynamic programming stores the largest all-1 square ending at each cell.
r, c = map(int, input().split()); m = [list(map(int, input().split()))[:c] for _ in range(r)]
dp = [[0] * (c + 1) for _ in range(r + 1)]; best = 0
for i in range(1, r + 1):
    for j in range(1, c + 1):
        if m[i - 1][j - 1] == 1:
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
            best = max(best, dp[i][j])
print(best)
