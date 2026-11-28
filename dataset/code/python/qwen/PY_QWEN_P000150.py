rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
flat = sorted([x for row in matrix for x in row])
idx = 0
for i in range(rows):
    for j in range(cols):
        matrix[i][j] = flat[idx]
        idx += 1
for row in matrix:
    print(" ".join(map(str, row)))
