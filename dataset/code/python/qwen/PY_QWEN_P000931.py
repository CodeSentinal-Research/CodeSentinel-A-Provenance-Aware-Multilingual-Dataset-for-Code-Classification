import sys
def solve():
    d = sys.stdin.read().split()
    n, m = int(d[0]), int(d[1])
    A = []
    idx = 2
    for i in range(n):
        A.append(list(map(int, d[idx:idx+m])))
        idx += m
    for j in range(m):
        print(" ".join(str(A[i][j]) for i in range(n)))
solve()
