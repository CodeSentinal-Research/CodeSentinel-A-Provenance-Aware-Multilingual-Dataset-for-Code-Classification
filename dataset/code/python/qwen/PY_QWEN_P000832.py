import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    k = int(d[n+1])
    l, r = max(nums), sum(nums)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        curr_sum = 0
        splits = 1
        for x in nums:
            if curr_sum + x > mid:
                splits += 1
                curr_sum = x
            else:
                curr_sum += x
        if splits <= k:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
