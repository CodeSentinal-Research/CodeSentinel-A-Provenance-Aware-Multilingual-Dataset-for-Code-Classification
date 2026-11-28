import sys
import bisect
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    houses = sorted(list(map(int, d[1:n+1])))
    m = int(d[n+1])
    heaters = sorted(list(map(int, d[n+2:n+2+m])))
    ans = 0
    for h in houses:
        idx = bisect.bisect_left(heaters, h)
        dist = float('inf')
        if idx < m: dist = min(dist, heaters[idx] - h)
        if idx > 0: dist = min(dist, h - heaters[idx-1])
        ans = max(ans, dist)
    print(ans)
solve()
