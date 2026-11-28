import sys
def solve():
    d = sys.stdin.read().split()
    a, b = d[0], d[1]
    print(bin(int(a, 2) + int(b, 2))[2:])
solve()
