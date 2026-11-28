import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, k = int(d[0]), int(d[1])
    q = list(range(1, n + 1))
    idx = 0
    while len(q) > 1:
        idx = (idx + k - 1) % len(q)
        q.pop(idx)
    print(q[0])
solve()
