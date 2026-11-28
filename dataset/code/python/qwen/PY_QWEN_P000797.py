import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    pref = {0: 1}
    curr = 0
    res = 0
    for x in arr:
        curr += 1 if x == 1 else -1
        res += pref.get(curr, 0)
        pref[curr] = pref.get(curr, 0) + 1
    print(res)
solve()
