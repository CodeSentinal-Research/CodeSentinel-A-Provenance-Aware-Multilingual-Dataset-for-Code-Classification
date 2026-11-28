import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, K = int(d[0]), int(d[1])
    def rec(n, k):
        if n == 1: return 0
        if k % 2 == 1: return rec(n - 1, (k + 1) // 2)
        else: return 1 - rec(n - 1, k // 2)
    print(rec(N, K))
solve()
