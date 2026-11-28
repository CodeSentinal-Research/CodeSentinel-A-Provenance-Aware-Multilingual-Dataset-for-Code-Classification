n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    row = []
    for j in range(n):
        if j <= i:
            row.append(str(matrix[i][j]))
        else:
            row.append("0")
    print(" ".join(row))
