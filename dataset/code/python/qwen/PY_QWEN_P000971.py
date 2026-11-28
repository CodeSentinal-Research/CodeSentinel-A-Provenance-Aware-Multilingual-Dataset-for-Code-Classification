import sys
def solve():
    d = sys.stdin.read().split()
    a, b = int(d[0]), int(d[1])
    f0, f1 = int(d[2]), int(d[3])
    n = int(d[4])
    if n == 0: print(f0)
    elif n == 1: print(f1)
    else:
        x, y = f0, f1
        for _ in range(2, n + 1):
            x, y = y, a * y + b * x
        print(y)
solve()
