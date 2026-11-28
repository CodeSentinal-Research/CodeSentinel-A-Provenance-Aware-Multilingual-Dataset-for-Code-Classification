import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    arr = list(map(int, d[1:n+1]))
    q = int(d[n+1])
    idx = n + 2
    for _ in range(q):
        l, r, x = int(d[idx]), int(d[idx+1]), int(d[idx+2])
        idx += 3
        count = sum(1 for i in range(l-1, r) if arr[i] % x == 0)
        print(count)
solve()
