n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
found = False
for i in range(n):
    min_row = min(matrix[i])
    min_idx = matrix[i].index(min_row)
    is_max_col = True
    for r in range(n):
        if matrix[r][min_idx] > min_row:
            is_max_col = False
            break
    if is_max_col:
        print(min_row)
        found = True
        break
if not found:
    print("No Saddle Point")
