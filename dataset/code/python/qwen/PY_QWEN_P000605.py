import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    res = []
    mx = -float('inf')
    for x in reversed(arr):
        if x >= mx:
            res.append(x)
            mx = x
    print(" ".join(map(str, res[::-1])))
solve()
