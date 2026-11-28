import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    position = sorted(list(map(int, d[1:n+1])))
    m = int(d[n+1])
    l, r = 0, position[-1] - position[0]
    ans = 0
    while l <= r:
        mid = (l + r) // 2
        count = 1
        last = position[0]
        for i in range(1, n):
            if position[i] - last >= mid:
                count += 1
                last = position[i]
        if count >= m:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
solve()
