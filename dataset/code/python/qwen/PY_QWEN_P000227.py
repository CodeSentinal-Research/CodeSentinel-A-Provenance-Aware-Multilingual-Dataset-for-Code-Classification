rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
max_sum = float('-inf')
for l in range(cols):
    temp = [0] * rows
    for r in range(l, cols):
        for i in range(rows):
            temp[i] += matrix[i][r]
        curr = 0
        best = float('-inf')
        for x in temp:
            curr = max(x, curr + x)
            best = max(best, curr)
        max_sum = max(max_sum, best)
print(max_sum)
