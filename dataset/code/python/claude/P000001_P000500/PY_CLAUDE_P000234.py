
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
rows = set(); cols = set()
for i in range(r):
    for j in range(c):
        if A[i][j]: rows.add(i); cols.add(j)
for i in range(r):
    print(*[1 if i in rows or j in cols else A[i][j] for j in range(c)])
