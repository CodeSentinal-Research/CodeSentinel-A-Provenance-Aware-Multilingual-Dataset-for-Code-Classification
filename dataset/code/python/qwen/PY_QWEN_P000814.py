import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    bad = int(d[1]) if len(d) > 1 else n
    l, r = 1, n
    ans = n
    while l <= r:
        mid = (l + r) // 2
        if mid >= bad:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
