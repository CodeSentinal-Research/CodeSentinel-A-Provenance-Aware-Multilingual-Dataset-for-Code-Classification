import sys
def solve():
    d = sys.stdin.read().split()
    a, m = int(d[0]), int(d[1])
    try:
        print(pow(a, -1, m))
    except ValueError:
        print(-1)
solve()
