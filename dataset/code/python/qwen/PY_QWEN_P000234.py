rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
row_flags = [False] * rows
col_flags = [False] * cols
for i in range(rows):
    for j in range(cols):
        if matrix[i][j] == 1:
            row_flags[i] = True
            col_flags[j] = True
for i in range(rows):
    for j in range(cols):
        if row_flags[i] or col_flags[j]:
            matrix[i][j] = 1
for row in matrix:
    print(" ".join(map(str, row)))
