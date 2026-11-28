import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    sl = set()
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "search":
            v = int(d[idx]); idx += 1
            print("true" if v in sl else "false")
        elif op == "add":
            sl.add(int(d[idx])); idx += 1
        elif op == "erase":
            v = int(d[idx]); idx += 1
            sl.discard(v)
solve()
