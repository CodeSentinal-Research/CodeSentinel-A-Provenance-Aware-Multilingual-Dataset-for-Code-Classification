import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    grid = [list(map(int, d[2+i*M:2+(i+1)*M])) for i in range(N)]
    pref = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            pref[i+1][j+1] = grid[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j]
    for row in pref[1:]: print(" ".join(map(str, row[1:])))
solve()
