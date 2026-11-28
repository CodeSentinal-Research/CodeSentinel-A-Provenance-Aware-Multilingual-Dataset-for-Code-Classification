import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    print(n * (n + 1) // 2)
solve()
