n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
max_val = [[0] * n for _ in range(n)]
max_val[n-1][n-1] = matrix[n-1][n-1]
for j in range(n-2, -1, -1):
    max_val[n-1][j] = max(matrix[n-1][j], max_val[n-1][j+1])
for i in range(n-2, -1, -1):
    max_val[i][n-1] = max(matrix[i][n-1], max_val[i+1][n-1])
for i in range(n-2, -1, -1):
    for j in range(n-2, -1, -1):
        max_val[i][j] = max(matrix[i][j], max(max_val[i+1][j], max_val[i][j+1]))
ans = float('-inf')
for i in range(n-1):
    for j in range(n-1):
        ans = max(ans, max_val[i+1][j+1] - matrix[i][j])
print(ans)
