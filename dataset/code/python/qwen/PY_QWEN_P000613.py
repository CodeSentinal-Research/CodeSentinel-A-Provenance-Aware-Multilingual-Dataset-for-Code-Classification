import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    seen = set()
    res = []
    for x in arr:
        if x not in seen:
            res.append(x)
            seen.add(x)
    print(" ".join(map(str, res)))
solve()
