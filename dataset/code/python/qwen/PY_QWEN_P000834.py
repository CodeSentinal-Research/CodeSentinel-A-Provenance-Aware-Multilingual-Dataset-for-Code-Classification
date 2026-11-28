import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    boards = list(map(int, d[1:n+1]))
    painters = int(d[n+1])
    if painters > n:
        painters = n
    l, r = max(boards), sum(boards)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        curr_sum = 0
        req_painters = 1
        for b in boards:
            if curr_sum + b > mid:
                req_painters += 1
                curr_sum = b
            else:
                curr_sum += b
        if req_painters <= painters:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
