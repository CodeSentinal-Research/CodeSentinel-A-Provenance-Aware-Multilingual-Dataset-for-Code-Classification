import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    res = []
    def rec(i, curr):
        if i == n:
            res.append(curr[:])
            return
        rec(i + 1, curr)
        curr.append(arr[i])
        rec(i + 1, curr)
        curr.pop()
    rec(0, [])
    for x in res: print(" ".join(map(str, x)))
solve()
