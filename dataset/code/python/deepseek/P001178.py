def maxGold(R, C, grid):
    dp = [[0] * C for _ in range(R)]
    dp[0] = grid[0]
    for i in range(1, R):
        dp[i] = [0] * C
        dp[i][0] = dp[i-1][0] + grid[i][0]
        for j in range(1, C):
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + grid[i][j]
            if j < C-1:
                dp[i][j] = max(dp[i][j], dp[i-1][j+1]) + grid[i][j]
    return max(dp[-1])

R = int(input())
C = int(input())
grid = []
for _ in range(R):
    row = list(map(int, input().split()))
    grid.append(row)

print(maxGold(R, C, grid))