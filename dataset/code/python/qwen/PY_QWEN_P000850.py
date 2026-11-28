import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, k = int(d[0]), int(d[1])
    if (n >> k) & 1:
        print("true")
    else:
        print("false")
solve()
