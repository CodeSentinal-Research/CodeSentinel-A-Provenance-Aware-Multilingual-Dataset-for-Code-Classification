import sys
import math
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    l, r = max(nums), sum(nums)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        curr = 0
        valid = True
        for i in range(n - 1, -1, -1):
            if curr + nums[i] > mid:
                valid = False
                break
            curr += nums[i]
        if valid:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
