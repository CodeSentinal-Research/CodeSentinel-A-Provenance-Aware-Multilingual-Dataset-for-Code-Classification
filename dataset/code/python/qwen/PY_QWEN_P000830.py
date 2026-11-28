import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    piles = list(map(int, d[1:n+1]))
    h = int(d[n+1])
    l, r = 1, max(piles)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        hours = sum(math.ceil(p / mid) for p in piles)
        if hours <= h:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
