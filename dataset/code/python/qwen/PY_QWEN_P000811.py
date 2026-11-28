import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    target = int(d[1]) if len(d) > 1 else 1
    l, r = 1, n
    while l <= r:
        mid = (l + r) // 2
        if mid == target:
            print(mid)
            return
        elif mid < target:
            l = mid + 1
        else:
            r = mid - 1
solve()
