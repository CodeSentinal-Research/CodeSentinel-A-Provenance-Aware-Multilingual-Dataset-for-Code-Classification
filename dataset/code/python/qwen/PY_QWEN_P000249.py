r1, c1 = map(int, input().split())
m1 = [list(map(int, input().split())) for _ in range(r1)]
r2, c2 = map(int, input().split())
m2 = [list(map(int, input().split())) for _ in range(r2)]
res = [[0] * c2 for _ in range(r1)]
for i in range(r1):
    for j in range(c2):
        for k in range(c1):
            res[i][j] += m1[i][k] * m2[k][j]
for row in res:
    print(" ".join(map(str, row)))
