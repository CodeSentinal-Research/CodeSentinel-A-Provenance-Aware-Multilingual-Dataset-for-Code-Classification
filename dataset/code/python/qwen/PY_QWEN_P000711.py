import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, K = int(d[0]), int(d[1])
    res = []
    def rec(start, curr):
        if len(curr) == K:
            res.append(curr[:])
            return
        for i in range(start, N + 1):
            curr.append(i)
            rec(i + 1, curr)
            curr.pop()
    rec(1, [])
    for x in res: print(" ".join(map(str, x)))
solve()
