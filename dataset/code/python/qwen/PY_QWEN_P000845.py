import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    k = int(d[n+1])
    l, r = 0, max(nums)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        count = 0
        i = 0
        while i < n:
            if nums[i] <= mid:
                count += 1
                i += 2
            else:
                i += 1
        if count >= k:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
