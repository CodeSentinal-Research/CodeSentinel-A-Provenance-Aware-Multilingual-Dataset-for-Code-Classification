import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    res = []
    curr = 0
    for x in arr:
        if x == 0:
            if curr > 0: res.append(curr)
            curr = 0
        else:
            curr += x
    print(" ".join(map(str, res)))
solve()
