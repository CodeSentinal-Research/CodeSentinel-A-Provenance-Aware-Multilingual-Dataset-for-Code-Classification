import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    encoded = list(map(int, d[1:n+1]))
    first = int(d[n+1])
    res = [first]
    for x in encoded:
        res.append(res[-1] ^ x)
    print(" ".join(map(str, res)))
solve()
