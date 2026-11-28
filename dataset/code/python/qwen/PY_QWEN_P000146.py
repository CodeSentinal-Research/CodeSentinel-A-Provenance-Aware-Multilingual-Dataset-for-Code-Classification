rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
dp = [[0] * cols for _ in range(rows)]
max_size = 0
for i in range(rows):
    for j in range(cols):
        if matrix[i][j] == 1:
            if i == 0 or j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            max_size = max(max_size, dp[i][j])
print(max_size)
