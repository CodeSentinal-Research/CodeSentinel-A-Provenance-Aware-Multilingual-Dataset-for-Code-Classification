def max_area(matrix):
    max_area = 0
    rows, cols = len(matrix), len(matrix[0])

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 1:
                min_width = cols
                for k in range(j + 1, cols):
                    if matrix[i][k] == 1:
                        min_width = min(min_width, k - j)
                max_area = max(max_area, min_width * (i + 1))

    return max_area


rows, cols = map(int, input().split())
matrix = []
for _ in range(rows):
    matrix.append(list(map(int, input().split())))

print(max_area(matrix))

This program traverses each cell of the matrix and for each 1, it finds the minimum width of the rectangle for this row. It keeps updating the maximum area found so far.