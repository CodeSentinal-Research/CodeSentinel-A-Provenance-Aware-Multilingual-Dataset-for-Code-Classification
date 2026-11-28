import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    stations = sorted(list(map(int, d[1:n+1])))
    k = int(d[n+1])
    l, r = 0.0, float(stations[-1] - stations[0])
    for _ in range(100):
        mid = (l + r) / 2
        count = 0
        for i in range(1, n):
            count += int((stations[i] - stations[i-1]) / mid)
        if count > k:
            l = mid
        else:
            r = mid
    print(f"{r:.6f}")
solve()
