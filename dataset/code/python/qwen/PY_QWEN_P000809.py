import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, target = int(d[0]), int(d[1])
    nums = list(map(int, d[2:2+n]))
    l, r = 0, n - 1
    ans = -1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] == target:
            ans = mid
            break
        elif nums[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
