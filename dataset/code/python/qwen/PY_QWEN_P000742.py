import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    def rec(i):
        if i > N: return
        print(i, end=" ")
        rec(i + 1)
    rec(1)
solve()
