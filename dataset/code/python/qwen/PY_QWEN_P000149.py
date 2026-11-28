rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
max_ones = -1
max_row = -1
for i in range(rows):
    ones = sum(matrix[i])
    if ones > max_ones:
        max_ones = ones
        max_row = i
print(max_row)
