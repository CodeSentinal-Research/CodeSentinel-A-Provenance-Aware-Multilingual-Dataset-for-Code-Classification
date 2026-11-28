import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    grid = [list(map(int, d[2+i*M:2+(i+1)*M])) for i in range(N)]
    K = int(d[2+N*M])
    pref = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            pref[i+1][j+1] = grid[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j]
    res = [[0] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            r1, c1 = max(0, i - K), max(0, j - K)
            r2, c2 = min(N - 1, i + K), min(M - 1, j + K)
            res[i][j] = pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]
    for row in res:
        print(" ".join(map(str, row)))
solve()
