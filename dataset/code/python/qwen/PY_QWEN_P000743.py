import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(n):
        if n == 1: return
        for i in range(n - 1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
        rec(n - 1)
    rec(n)
    print(" ".join(map(str, arr)))
solve()
