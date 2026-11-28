rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
res = []
for d in range(rows + cols - 1):
    if d % 2 == 0:
        r = min(d, rows - 1)
        c = d - r
        while r >= 0 and c < cols:
            res.append(matrix[r][c])
            r -= 1
            c += 1
    else:
        c = min(d, cols - 1)
        r = d - c
        while c >= 0 and r < rows:
            res.append(matrix[r][c])
            r += 1
            c -= 1
print(" ".join(map(str, res)))
