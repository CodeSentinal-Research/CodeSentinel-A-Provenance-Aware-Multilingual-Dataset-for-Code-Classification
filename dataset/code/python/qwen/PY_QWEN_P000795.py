import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    pref = {0: 1}
    curr = 0
    res = 0
    for x in arr:
        curr = (curr + x) % k
        res += pref.get(curr, 0)
        pref[curr] = pref.get(curr, 0) + 1
    print(res)
solve()
