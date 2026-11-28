import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    A = []
    idx = 1
    for i in range(n):
        A.append(list(map(int, d[idx:idx+n])))
        idx += n
    s = sum(A[i][i] for i in range(n))
    s += sum(A[i][n - 1 - i] for i in range(n))
    if n % 2 != 0:
        s -= A[n // 2][n // 2]
    print(s)
solve()
