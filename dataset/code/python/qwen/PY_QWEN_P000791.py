import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    pref = {0: -1}
    curr = 0
    mx = 0
    for i, x in enumerate(arr):
        curr += x
        if curr - k in pref: mx = max(mx, i - pref[curr - k])
        if curr not in pref: pref[curr] = i
    print(mx)
solve()
