import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n > 0 and (n & (n - 1)) == 0:
        print("true")
    else:
        print("false")
solve()
