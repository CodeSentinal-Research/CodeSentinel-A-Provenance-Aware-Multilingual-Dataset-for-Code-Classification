import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    x, y = int(d[0]), int(d[1])
    print(bin(x ^ y).count('1'))
solve()
