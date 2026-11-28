import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, l1 = int(d[0]), list(map(int, d[1:int(d[0])+1]))
    m, l2 = int(d[int(d[0])+1]), list(map(int, d[int(d[0])+2:]))
    print("true" if l1 == l2 else "false")
solve()
