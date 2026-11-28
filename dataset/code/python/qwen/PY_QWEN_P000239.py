rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
res = []
if rows == 1:
    res = matrix[0]
elif cols == 1:
    res = [matrix[i][0] for i in range(rows)]
else:
    res.extend(matrix[0])
    for i in range(1, rows - 1):
        res.append(matrix[i][-1])
    res.extend(matrix[-1][::-1])
    for i in range(rows - 2, 0, -1):
        res.append(matrix[i][0])
print(" ".join(map(str, res)))
