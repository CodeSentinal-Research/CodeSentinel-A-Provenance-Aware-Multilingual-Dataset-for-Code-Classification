import sys
def solve():
    n = sys.stdin.read().split()[0]
    even = sum(1 for c in n if int(c) % 2 == 0)
    odd = len(n) - even
    print(even, odd)
solve()
