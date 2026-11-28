n, h = map(int, input().split())
arr = list(map(int, input().split()))
import math
l, r = 1, max(arr)
ans = r
while l <= r:
    mid = (l + r) // 2
    hours = sum(math.ceil(x / mid) for x in arr)
    if hours <= h:
        ans = mid
        r = mid - 1
    else:
        l = mid + 1
print(ans)
