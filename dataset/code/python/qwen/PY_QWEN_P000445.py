rows, cols, target = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
found = False
for i in range(rows):
    for j in range(cols):
        if matrix[i][j] == target:
            found = True
            break
print("Found" if found else "Not Found")
