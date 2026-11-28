rows, cols = map(int, input().split())
m1 = [list(map(int, input().split())) for _ in range(rows)]
m2 = [list(map(int, input().split())) for _ in range(rows)]
for i in range(rows):
    print(" ".join(map(str, [m1[i][j] + m2[i][j] for j in range(cols)])))
