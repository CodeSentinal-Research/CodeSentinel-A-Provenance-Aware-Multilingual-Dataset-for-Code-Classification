
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
best = float('-inf')
for l in range(c):
    row = [0]*r
    for ri in range(l, c):
        for i in range(r): row[i] += A[i][ri]
        cur = mn = 0; s = float('-inf')
        for x in row:
            cur += x; s = max(s, cur-mn); mn = min(mn, cur)
        best = max(best, s)
print(best)
