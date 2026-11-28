import sys
def mat_mul(A, B):
    n = len(A)
    C = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C
def solve():
    d = sys.stdin.read().split()
    n, k = int(d[0]), int(d[1])
    A = []
    idx = 2
    for i in range(n):
        A.append([int(x) for x in d[idx:idx+n]])
        idx += n
    res = [[1 if i==j else 0 for j in range(n)] for i in range(n)]
    base = A
    while k > 0:
        if k % 2 == 1:
            res = mat_mul(res, base)
        base = mat_mul(base, base)
        k //= 2
    for row in res:
        print(" ".join(map(str, row)))
solve()
