import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    p = 1
    for x in d[0]: p *= int(x)
    print(p)
solve()
