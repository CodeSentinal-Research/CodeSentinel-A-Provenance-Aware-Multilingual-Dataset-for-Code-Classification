rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
total = 0
for i in range(rows):
    for j in range(cols):
        if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
            total += matrix[i][j]
print(total)
