import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    weights = list(map(int, d[1:n+1]))
    days = int(d[n+1])
    l, r = max(weights), sum(weights)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        curr_days = 1
        curr_sum = 0
        for w in weights:
            if curr_sum + w > mid:
                curr_days += 1
                curr_sum = 0
            curr_sum += w
        if curr_days <= days:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
