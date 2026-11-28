import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(idx):
        if idx == n: return
        i = idx
        while i > 0 and arr[i-1] > arr[i]:
            arr[i-1], arr[i] = arr[i], arr[i-1]
            i -= 1
        rec(idx + 1)
    rec(0)
    print(" ".join(map(str, arr)))
solve()
