rows, cols, target = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
r, c = 0, cols - 1
found = False
while r < rows and c >= 0:
    if matrix[r][c] == target:
        found = True
        break
    elif matrix[r][c] > target:
        c -= 1
    else:
        r += 1
print("Found" if found else "Not Found")
