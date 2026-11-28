import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    bloomDay = list(map(int, d[1:n+1]))
    m, k = int(d[n+1]), int(d[n+2])
    if m * k > n:
        print("-1")
        return
    l, r = 1, max(bloomDay)
    ans = -1
    while l <= r:
        mid = (l + r) // 2
        bouquets = 0
        flowers = 0
        for b in bloomDay:
            if b <= mid:
                flowers += 1
                if flowers == k:
                    bouquets += 1
                    flowers = 0
            else:
                flowers = 0
        if bouquets >= m:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
