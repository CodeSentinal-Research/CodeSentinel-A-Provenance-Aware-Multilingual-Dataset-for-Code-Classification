import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    res = []
    for x in arr:
        if not res or res[-1] != x: res.append(x)
    print(" ".join(map(str, res)))
solve()
