import sys
def solve():
    n = sys.stdin.read().split()[0]
    if n == '0':
        print(1)
    else:
        print(len(n.lstrip('-')))
solve()
