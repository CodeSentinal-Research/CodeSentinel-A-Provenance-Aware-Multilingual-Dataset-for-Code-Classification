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
        for i in range(1, M - c): rec(r, c + i, path + f"H{i}")
        for i in range(1, N - r): rec(r + i, c, path + f"V{i}")
        for i in range(1, min(N - r, M - c)): rec(r + i, c + i, path + f"D{i}")
    rec(0, 0, "")
    for x in sorted(res): print(x)
solve()
