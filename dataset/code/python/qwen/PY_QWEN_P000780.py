import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    pref = [0] * n
    pref[0] = arr[0]
    for i in range(1, n): pref[i] = pref[i-1] + arr[i]
    print(" ".join(map(str, pref)))
solve()
