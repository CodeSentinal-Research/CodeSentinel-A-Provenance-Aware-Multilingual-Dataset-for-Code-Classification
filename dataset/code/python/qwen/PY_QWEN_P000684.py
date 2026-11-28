import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    a, b = 0, 1
    for _ in range(n): a, b = b, a + b
    print(a)
solve()
