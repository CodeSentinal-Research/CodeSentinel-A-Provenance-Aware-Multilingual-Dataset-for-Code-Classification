import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    threshold = int(d[n+1])
    l, r = 1, max(nums)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        s = sum(math.ceil(x / mid) for x in nums)
        if s <= threshold:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
