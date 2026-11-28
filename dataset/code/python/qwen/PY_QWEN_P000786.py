import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    tot = sum(arr)
    left = 0
    res = []
    for x in arr:
        right = tot - left - x
        res.append(abs(left - right))
        left += x
    print(" ".join(map(str, res)))
solve()
