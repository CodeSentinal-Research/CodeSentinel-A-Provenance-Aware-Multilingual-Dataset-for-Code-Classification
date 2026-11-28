import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n == 0:
        print(0)
    else:
        print(1 + (n - 1) % 9)
solve()
