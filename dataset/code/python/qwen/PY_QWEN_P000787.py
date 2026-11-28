import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    tot = sum(arr)
    left = 0
    for i in range(n):
        if left == tot - left - arr[i]: print(i); return
        left += arr[i]
    print("-1")
solve()
