import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    candies = list(map(int, d[1:n+1]))
    k = int(d[n+1])
    l, r = 0, max(candies)
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        if mid == 0:
            l = mid + 1
            continue
        count = sum(c // mid for c in candies)
        if count >= k:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
