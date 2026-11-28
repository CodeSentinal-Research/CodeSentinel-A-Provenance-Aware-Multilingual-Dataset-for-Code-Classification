import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    m = int(d[1])
    quantities = list(map(int, d[2:2+m]))
    l, r = 1, max(quantities)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        stores_needed = sum(math.ceil(q / mid) for q in quantities)
        if stores_needed <= n:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
