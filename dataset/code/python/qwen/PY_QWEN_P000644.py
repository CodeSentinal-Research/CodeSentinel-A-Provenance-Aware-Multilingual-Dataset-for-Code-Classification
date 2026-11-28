import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, x, y = int(d[0]), list(map(int, d[1:-2])), int(d[-2]), int(d[-1])
    if x in arr and y in arr:
        ix, iy = arr.index(x), arr.index(y)
        arr[ix], arr[iy] = arr[iy], arr[ix]
    print(" ".join(map(str, arr)))
solve()
