import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    print(" ".join(map(str, range(1, n + 1))))
solve()
