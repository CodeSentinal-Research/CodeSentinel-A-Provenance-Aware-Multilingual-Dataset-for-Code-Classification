import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, index, maxSum = int(d[0]), int(d[1]), int(d[2])
    l, r = 1, maxSum
    ans = 1
    def calc(val, cnt):
        if cnt <= val:
            return (val + val - cnt + 1) * cnt // 2
        else:
            return (val + 1) * val // 2 + (cnt - val)
    while l <= r:
        mid = (l + r) // 2
        left_cnt = index
        right_cnt = n - 1 - index
        total = mid + calc(mid - 1, left_cnt) + calc(mid - 1, right_cnt)
        if total <= maxSum:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
