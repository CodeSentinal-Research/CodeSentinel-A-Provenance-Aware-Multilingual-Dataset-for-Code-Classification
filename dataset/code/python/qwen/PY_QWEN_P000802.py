import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    grid = [list(map(int, d[2+i*M:2+(i+1)*M])) for i in range(N)]
    threshold = int(d[2+N*M])
    pref = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            pref[i+1][j+1] = grid[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j]
    def get_sum(r1, c1, r2, c2):
        return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]
    l, r = 1, min(N, M)
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        found = False
        for i in range(N - mid + 1):
            for j in range(M - mid + 1):
                if get_sum(i, j, i + mid - 1, j + mid - 1) <= threshold:
                    found = True
                    break
            if found: break
        if found:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
