import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    poly = {}
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "insert":
            c, e = int(d[idx]), int(d[idx+1]); idx += 2
            poly[e] = poly.get(e, 0) + c
        elif op == "delete":
            e = int(d[idx]); idx += 1
            if e in poly: del poly[e]
        elif op == "evaluate":
            x = int(d[idx]); idx += 1
            print(sum(c * (x ** e) for e, c in poly.items()))
        elif op == "display":
            print(" ".join(f"{poly[e]}x^{e}" for e in sorted(poly.keys(), reverse=True)))
solve()
