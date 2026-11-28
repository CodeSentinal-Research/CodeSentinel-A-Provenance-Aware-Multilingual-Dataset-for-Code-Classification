import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    A = []
    idx = 1
    for i in range(n):
        A.append(list(map(int, d[idx:idx+n])))
        idx += n
    res = [[A[n - 1 - j][i] for j in range(n)] for i in range(n)]
    for row in res:
        print(" ".join(map(str, row)))
solve()
