import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    price = sorted(list(map(int, d[1:n+1])))
    k = int(d[n+1])
    l, r = 0, price[-1] - price[0]
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        count = 1
        last = price[0]
        for i in range(1, n):
            if price[i] - last >= mid:
                count += 1
                last = price[i]
        if count >= k:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
