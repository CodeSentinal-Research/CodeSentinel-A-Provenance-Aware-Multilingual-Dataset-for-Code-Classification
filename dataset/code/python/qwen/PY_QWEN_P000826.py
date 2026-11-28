import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    l, r = 0, n
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        if mid * (mid + 1) // 2 <= n:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
