import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    arr = list(map(int, d[1:n+1]))
    g = int(d[n+1])
    groups = list(map(int, d[n+2:n+2+g]))
    res = []
    idx = 0
    for sz in groups:
        chunk = arr[idx:idx+sz]
        if len(chunk) == sz: chunk.reverse()
        res.extend(chunk)
        idx += sz
    res.extend(arr[idx:])
    print(" ".join(map(str, res)))
solve()
