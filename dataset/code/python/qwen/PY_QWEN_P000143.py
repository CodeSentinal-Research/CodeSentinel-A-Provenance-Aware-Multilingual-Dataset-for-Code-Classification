rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
transposed = [[matrix[i][j] for i in range(rows)] for j in range(cols)]
for row in transposed:
    print(" ".join(map(str, row)))
