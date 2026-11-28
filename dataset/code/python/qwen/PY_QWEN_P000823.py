import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    k = int(d[n+1])
    l, r = 0, n - 1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] - mid - 1 < k:
            l = mid + 1
        else:
            r = mid - 1
    print(l + k)
solve()
