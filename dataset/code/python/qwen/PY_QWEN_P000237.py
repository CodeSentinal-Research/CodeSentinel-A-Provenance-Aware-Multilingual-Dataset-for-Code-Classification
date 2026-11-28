rows, cols, k = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
k = k % cols
for i in range(rows):
    matrix[i] = matrix[i][-k:] + matrix[i][:-k]
for row in matrix:
    print(" ".join(map(str, row)))
