import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(l, r):
        if l >= r: return
        p = arr[r]
        i = l - 1
        for j in range(l, r):
            if arr[j] <= p:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i+1], arr[r] = arr[r], arr[i+1]
        rec(l, i)
        rec(i + 2, r)
    rec(0, n - 1)
    print(" ".join(map(str, arr)))
solve()
