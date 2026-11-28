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
    Q = int(d[2+N*M])
    idx = 3 + N * M
    for _ in range(Q):
        r1, c1, r2, c2 = int(d[idx]), int(d[idx+1]), int(d[idx+2]), int(d[idx+3])
        idx += 4
        print(pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1])
solve()
