import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, K = int(d[0]), int(d[1])
    def rec(n, k):
        if n == 1: return 0
        return (rec(n - 1, k) + k) % n
    print(rec(N, K) + 1)
solve()
