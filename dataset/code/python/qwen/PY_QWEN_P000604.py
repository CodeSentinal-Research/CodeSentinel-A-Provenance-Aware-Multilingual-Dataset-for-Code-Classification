import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n1, l1 = int(d[0]), list(map(int, d[1:int(d[0])+1]))
    n2, l2 = int(d[int(d[0])+1]), list(map(int, d[int(d[0])+2:int(d[0])+2+int(d[int(d[0])+1])]))
    s = str(int("".join(map(str, l1))) + int("".join(map(str, l2))))
    print(" ".join(s))
solve()
