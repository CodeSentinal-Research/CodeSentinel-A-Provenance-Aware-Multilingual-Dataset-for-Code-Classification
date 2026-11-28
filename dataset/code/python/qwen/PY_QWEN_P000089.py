n = int(input())
if n == 0:
    print(0)
else:
    l, r = 1, n
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        if mid * mid <= n:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
