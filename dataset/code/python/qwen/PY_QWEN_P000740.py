import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    res = []
    def rec(r, c, path):
        if r == N - 1 and c == M - 1:
            res.append(path)
            return
        if r + 1 < N: rec(r + 1, c, path + "V")
        if c + 1 < M: rec(r, c + 1, path + "H")
        if r + 1 < N and c + 1 < M: rec(r + 1, c + 1, path + "D")
    rec(0, 0, "")
    for x in sorted(res): print(x)
solve()
