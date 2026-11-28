n, d = map(int, input().split())
arr = list(map(int, input().split()))
l, r = max(arr), sum(arr)
ans = r
while l <= r:
    mid = (l + r) // 2
    days = 1
    curr = 0
    for x in arr:
        if curr + x > mid:
            days += 1
            curr = x
        else:
            curr += x
    if days <= d:
        ans = mid
        r = mid - 1
    else:
        l = mid + 1
print(ans)
