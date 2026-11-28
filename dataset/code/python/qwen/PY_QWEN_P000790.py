import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    pref = {0: -1}
    curr = 0
    for i, x in enumerate(arr):
        curr += x
        if k != 0 and curr % k in pref and i - pref[curr % k] > 1:
            print("true"); return
        if curr % k not in pref: pref[curr % k] = i
    print("false")
solve()
