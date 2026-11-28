import sys
def solve():
    n = sys.stdin.read().split()[0].lstrip('-')
    p = 1
    for c in n:
        p *= int(c)
    print(p)
solve()
