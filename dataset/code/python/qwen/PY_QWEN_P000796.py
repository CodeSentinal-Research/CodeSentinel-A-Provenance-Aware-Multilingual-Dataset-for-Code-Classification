import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, p = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    tot = sum(arr) % p
    if tot == 0: print("0"); return
    pref = {0: -1}
    curr = 0
    mn = n
    for i, x in enumerate(arr):
        curr = (curr + x) % p
        need = (curr - tot) % p
        if need in pref: mn = min(mn, i - pref[need])
        pref[curr] = i
    print(mn if mn < n else "-1")
solve()
