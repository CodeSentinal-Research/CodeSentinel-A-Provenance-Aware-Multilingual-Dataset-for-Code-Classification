rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
common = set(matrix[0])
for i in range(1, rows):
    common &= set(matrix[i])
print(" ".join(map(str, sorted(list(common)))))
