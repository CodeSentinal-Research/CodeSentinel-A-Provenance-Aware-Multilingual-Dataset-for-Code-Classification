import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    m = int(d[1])
    batteries = sorted(list(map(int, d[2:2+m])))
    l, r = 0, sum(batteries) // n
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        total = sum(min(b, mid) for b in batteries)
        if total >= n * mid:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
