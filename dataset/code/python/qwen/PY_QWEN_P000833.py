import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    pages = list(map(int, d[1:n+1]))
    students = int(d[n+1])
    if students > n:
        print("-1")
        return
    l, r = max(pages), sum(pages)
    ans = r
    while l <= r:
        mid = (l + r) // 2
        curr_sum = 0
        req_students = 1
        for p in pages:
            if curr_sum + p > mid:
                req_students += 1
                curr_sum = p
            else:
                curr_sum += p
        if req_students <= students:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
solve()
