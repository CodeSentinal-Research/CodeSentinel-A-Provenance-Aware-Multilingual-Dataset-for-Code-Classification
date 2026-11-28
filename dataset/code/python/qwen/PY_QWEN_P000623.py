import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    res = []
    i = 0
    rev = True
    while i < n:
        chunk = arr[i:i+k]
        if rev: chunk.reverse()
        res.extend(chunk)
        i += k
        rev = not rev
    print(" ".join(map(str, res)))
solve()
