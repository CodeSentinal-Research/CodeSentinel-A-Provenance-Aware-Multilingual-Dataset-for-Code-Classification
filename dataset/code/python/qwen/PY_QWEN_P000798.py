import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    pref = {0: -1}
    curr = 0
    mx = 0
    for i, x in enumerate(arr):
        curr += 1 if x == 1 else -1
        if curr in pref: mx = max(mx, i - pref[curr])
        else: pref[curr] = i
    print(mx)
solve()
