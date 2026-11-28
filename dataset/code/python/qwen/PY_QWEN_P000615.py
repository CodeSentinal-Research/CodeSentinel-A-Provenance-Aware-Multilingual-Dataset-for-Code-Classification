import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    res = []
    i = 0
    g = 1
    while i < len(arr):
        end = min(i + g, len(arr))
        chunk = arr[i:end]
        if len(chunk) % 2 == 0:
            chunk.reverse()
        res.extend(chunk)
        i = end
        g += 1
    print(" ".join(map(str, res)))
solve()
