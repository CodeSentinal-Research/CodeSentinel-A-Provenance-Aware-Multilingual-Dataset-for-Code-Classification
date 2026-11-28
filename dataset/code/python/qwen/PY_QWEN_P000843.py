import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = sorted(list(map(int, d[1:n+1])))
    p = int(d[n+1])
    l, r = 0, nums[-1] - nums[0]
    ans = r
    while l <= r:
        mid = (l + r) // 2
        count = 0
        i = 1
        while i < n:
            if nums[i] - nums[i-1] <= mid:
                count += 1
                i += 2
            else:
                i += 1
        if count >= p:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
