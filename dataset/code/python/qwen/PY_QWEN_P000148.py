n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
is_sym = True
for i in range(n):
    for j in range(n):
        if matrix[i][j] != matrix[j][i]:
            is_sym = False
            break
if is_sym:
    print("Symmetric")
else:
    print("Not Symmetric")
