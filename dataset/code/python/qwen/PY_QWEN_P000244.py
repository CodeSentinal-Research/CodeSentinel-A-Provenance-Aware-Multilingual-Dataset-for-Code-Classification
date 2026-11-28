rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
dp = [[0] * cols for _ in range(rows)]
dp[0][0] = matrix[0][0]
for i in range(rows):
    for j in range(cols):
        if i == 0 and j == 0: continue
        top = dp[i-1][j] if i > 0 else float('-inf')
        left = dp[i][j-1] if j > 0 else float('-inf')
        dp[i][j] = matrix[i][j] + max(top, left)
print(dp[rows-1][cols-1])
