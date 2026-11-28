import sys
import bisect
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, target = int(d[0]), int(d[1])
    nums = list(map(int, d[2:2+n]))
    l = bisect.bisect_left(nums, target)
    r = bisect.bisect_right(nums, target) - 1
    if l < n and nums[l] == target:
        print(l, r)
    else:
        print("-1 -1")
solve()
