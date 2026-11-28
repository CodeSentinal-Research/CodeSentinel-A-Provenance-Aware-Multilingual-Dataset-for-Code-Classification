rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
zero_rows = set()
zero_cols = set()
for i in range(rows):
    for j in range(cols):
        if matrix[i][j] == 0:
            zero_rows.add(i)
            zero_cols.add(j)
for i in range(rows):
    for j in range(cols):
        if i in zero_rows or j in zero_cols:
            matrix[i][j] = 0
for row in matrix:
    print(" ".join(map(str, row)))
