rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
max_sum = float('-inf')
for i in range(1, rows - 1):
    for j in range(1, cols - 1):
        s = matrix[i][j] + matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1]
        max_sum = max(max_sum, s)
print(max_sum)
