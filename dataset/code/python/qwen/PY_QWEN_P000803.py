import sys
from collections import defaultdict
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    grid = [list(map(int, d[2+i*M:2+(i+1)*M])) for i in range(N)]
    target = int(d[2+N*M])
    ans = 0
    for r1 in range(N):
        col_sum = [0] * M
        for r2 in range(r1, N):
            for c in range(M):
                col_sum[c] += grid[r2][c]
            pref = defaultdict(int)
            pref[0] = 1
            curr = 0
            for c in range(M):
                curr += col_sum[c]
                ans += pref[curr - target]
                pref[curr] += 1
    print(ans)
solve()
