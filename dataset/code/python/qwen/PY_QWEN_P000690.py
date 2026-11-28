import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    print(bin(int(d[0]))[2:])
solve()
