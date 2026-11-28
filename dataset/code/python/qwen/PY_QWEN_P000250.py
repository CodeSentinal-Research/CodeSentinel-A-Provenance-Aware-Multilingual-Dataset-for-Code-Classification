n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
def det(m):
    if len(m) == 1:
        return m[0][0]
    if len(m) == 2:
        return m[0][0]*m[1][1] - m[0][1]*m[1][0]
    d = 0
    for j in range(len(m)):
        sub = [[m[r][c] for c in range(len(m)) if c != j] for r in range(1, len(m))]
        d += ((-1)**j) * m[0][j] * det(sub)
    return d
print(det(matrix))
