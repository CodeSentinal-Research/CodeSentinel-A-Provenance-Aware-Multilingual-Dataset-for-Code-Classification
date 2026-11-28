import sys
def solve():
    d = sys.stdin.read().split()
    n, m, p = int(d[0]), int(d[1]), int(d[2])
    A = []
    idx = 3
    for i in range(n):
        A.append(list(map(int, d[idx:idx+m])))
        idx += m
    B = []
    for i in range(m):
        B.append(list(map(int, d[idx:idx+p])))
        idx += p
    C = [[0]*p for _ in range(n)]
    for i in range(n):
        for k in range(m):
            if A[i][k] != 0:
                for j in range(p):
                    if B[k][j] != 0:
                        C[i][j] += A[i][k] * B[k][j]
    for row in C:
        print(" ".join(map(str, row)))
solve()
