import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    for i in range(1, n): arr[i] += arr[i-1]
    print(" ".join(map(str, arr)))
solve()
