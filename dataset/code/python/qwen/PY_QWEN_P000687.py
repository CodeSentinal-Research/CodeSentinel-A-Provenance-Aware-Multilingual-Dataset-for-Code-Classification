import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    print(sum(int(x) for x in d[0]))
solve()
