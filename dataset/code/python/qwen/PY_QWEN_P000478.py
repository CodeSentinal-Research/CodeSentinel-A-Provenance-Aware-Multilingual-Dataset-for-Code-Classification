n, c = map(int, input().split())
stalls = sorted(list(map(int, input().split())))
l, r = 0, stalls[-1] - stalls[0]
ans = 0
while l <= r:
    mid = (l + r) // 2
    count = 1
    last = stalls[0]
    for i in range(1, n):
        if stalls[i] - last >= mid:
            count += 1
            last = stalls[i]
    if count >= c:
        ans = mid
        l = mid + 1
    else:
        r = mid - 1
print(ans)
