import sys
def solve():
    x = int(sys.stdin.read().split()[0])
    if x < 0:
        print("false")
    else:
        print("true" if str(x) == str(x)[::-1] else "false")
solve()
