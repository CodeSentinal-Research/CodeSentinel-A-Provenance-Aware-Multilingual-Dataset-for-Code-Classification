import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n & 1:
        print("Odd")
    else:
        print("Even")
solve()
