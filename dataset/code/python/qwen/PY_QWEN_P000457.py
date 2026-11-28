n, threshold = map(int, input().split())
arr = list(map(int, input().split()))
import math
l, r = 1, max(arr)
ans = r
while l <= r:
    mid = (l + r) // 2
    s = sum(math.ceil(x / mid) for x in arr)
    if s <= threshold:
        ans = mid
        r = mid - 1
    else:
        l = mid + 1
print(ans)
