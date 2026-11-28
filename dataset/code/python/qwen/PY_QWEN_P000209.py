rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
top, bottom, left, right = 0, rows - 1, 0, cols - 1
while top < bottom and left < right:
    prev = matrix[top + 1][left]
    for i in range(left, right + 1):
        curr = matrix[top][i]
        matrix[top][i] = prev
        prev = curr
    top += 1
    for i in range(top, bottom + 1):
        curr = matrix[i][right]
        matrix[i][right] = prev
        prev = curr
    right -= 1
    for i in range(right, left - 1, -1):
        curr = matrix[bottom][i]
        matrix[bottom][i] = prev
        prev = curr
    bottom -= 1
    for i in range(bottom, top - 1, -1):
        curr = matrix[i][left]
        matrix[i][left] = prev
        prev = curr
    left += 1
for row in matrix:
    print(" ".join(map(str, row)))
