import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, chars, K = int(d[0]), d[1:n+1], int(d[n+1])
    res = []
    def rec(curr):
        if len(curr) == K:
            res.append(curr)
            return
        for c in chars:
            rec(curr + c)
    rec("")
    for x in sorted(res): print(x)
solve()
