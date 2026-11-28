n, m = map(int, input().split())
arr = list(map(int, input().split()))
if m > n:
    print(-1)
else:
    l, r = max(arr), sum(arr)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        students = 1
        curr_sum = 0
        valid = True
        for x in arr:
            if curr_sum + x > mid:
                students += 1
                curr_sum = x
                if students > m:
                    valid = False
                    break
            else:
                curr_sum += x
        if valid:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
