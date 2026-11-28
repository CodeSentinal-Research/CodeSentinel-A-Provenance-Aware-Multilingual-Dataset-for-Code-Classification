import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    res = []
    for i in range(0, n, k):
        chunk = arr[i:i+k]
        chunk.reverse()
        res.extend(chunk)
    print(" ".join(map(str, res)))
solve()
