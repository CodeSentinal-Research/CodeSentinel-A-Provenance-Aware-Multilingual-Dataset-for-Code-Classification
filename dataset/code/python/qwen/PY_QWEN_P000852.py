import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, k = int(d[0]), int(d[1])
    print(n & ~(1 << k))
solve()
