import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, goal = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    pref = {0: 1}
    curr = 0
    res = 0
    for x in arr:
        curr += x
        if curr - goal in pref: res += pref[curr - goal]
        pref[curr] = pref.get(curr, 0) + 1
    print(res)
solve()
