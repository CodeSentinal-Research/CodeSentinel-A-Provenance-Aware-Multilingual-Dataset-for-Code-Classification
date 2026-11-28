n, m = map(int, input().split())
arr = list(map(int, input().split()))
l, r = max(arr), sum(arr)
ans = r
while l <= r:
    mid = (l + r) // 2
    parts = 1
    curr = 0
    for x in arr:
        if curr + x > mid:
            parts += 1
            curr = x
        else:
            curr += x
    if parts <= m:
        ans = mid
        r = mid - 1
    else:
        l = mid + 1
print(ans)
