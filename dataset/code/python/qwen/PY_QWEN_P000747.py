import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    def rec(n):
        if n <= 1: return 1
        return rec(n - 1) + rec(n - 2)
    print(rec(N))
solve()
