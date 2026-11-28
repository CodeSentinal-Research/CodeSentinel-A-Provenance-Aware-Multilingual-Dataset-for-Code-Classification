import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    print(oct(n)[2:], hex(n)[2:].upper())
solve()
