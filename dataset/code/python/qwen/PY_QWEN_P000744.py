import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(idx):
        if idx == n - 1: return
        min_idx = idx
        for i in range(idx + 1, n):
            if arr[i] < arr[min_idx]: min_idx = i
        arr[idx], arr[min_idx] = arr[min_idx], arr[idx]
        rec(idx + 1)
    rec(0)
    print(" ".join(map(str, arr)))
solve()
