import sys
def solve():
    d = sys.stdin.read().split()
    x = int(d[0])
    n = int(d[1])
    rems = list(map(int, d[2:2+n]))
    mods = list(map(int, d[2+n:2+2*n]))
    ok = True
    for r, m in zip(rems, mods):
        if x % m != r:
            ok = False
            break
    print("true" if ok else "false")
solve()
