import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    grid = [list(map(int, d[2+i*M:2+(i+1)*M])) for i in range(N)]
    res = 0
    def rec(r, c):
        nonlocal res
        if r == N - 1 and c == M - 1:
            res += 1
            return
        if r + 1 < N and grid[r+1][c] == 1: rec(r + 1, c)
        if c + 1 < M and grid[r][c+1] == 1: rec(r, c + 1)
    if grid[0][0] == 1: rec(0, 0)
    print(res)
solve()
