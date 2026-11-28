# problem title : Set Matrix Zeroes
# Record zero rows and columns before changing any matrix entries.
r, c = map(int, input().split()); m = [list(map(int, input().split()))[:c] for _ in range(r)]
rows = {i for i in range(r) if 0 in m[i]}
cols = {j for j in range(c) if any(m[i][j] == 0 for i in range(r))}
for i in range(r):
    for j in range(c):
        if i in rows or j in cols: m[i][j] = 0
for row in m: print(*row)
