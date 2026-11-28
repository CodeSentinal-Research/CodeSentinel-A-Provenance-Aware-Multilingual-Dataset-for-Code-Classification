import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    res = []
    curr = 0
    for x in arr:
        res.append(x)
        curr += x
        if curr == 0:
            res = []
    print(" ".join(map(str, res)))
solve()
