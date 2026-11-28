import sys
def solve():
    d = sys.stdin.read().split()
    n, m = int(d[0]), int(d[1])
    A = []
    idx = 2
    for i in range(n):
        A.append(list(map(int, d[idx:idx+m])))
        idx += m
    B = []
    for i in range(n):
        B.append(list(map(int, d[idx:idx+m])))
        idx += m
    for i in range(n):
        print(" ".join(str(A[i][j] + B[i][j]) for j in range(m)))
solve()
