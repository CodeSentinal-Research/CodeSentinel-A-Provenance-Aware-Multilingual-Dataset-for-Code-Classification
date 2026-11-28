import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    arr = list(map(int, d[1:n+1]))
    q = int(d[n+1])
    pref = [0] * (n + 1)
    for i in range(n): pref[i+1] = pref[i] + arr[i]
    idx = n + 2
    for _ in range(q):
        l, r = int(d[idx]), int(d[idx+1])
        idx += 2
        print(pref[r+1] - pref[l])
solve()
