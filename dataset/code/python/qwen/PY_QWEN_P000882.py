import sys
def solve():
    n = sys.stdin.read().split()[0].lstrip('-')
    print(sum(int(c) for c in n))
solve()
