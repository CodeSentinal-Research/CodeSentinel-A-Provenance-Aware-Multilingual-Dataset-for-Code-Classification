import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    res = []
    def rec(idx, curr):
        if idx == n:
            res.append(curr)
            return
        rec(idx + 1, curr + arr[idx])
        rec(idx + 1, curr)
    rec(0, 0)
    print(" ".join(map(str, sorted(res))))
solve()
