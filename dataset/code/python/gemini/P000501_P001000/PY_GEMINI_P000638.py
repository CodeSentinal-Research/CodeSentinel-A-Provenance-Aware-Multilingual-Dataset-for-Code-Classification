import sys
from collections import defaultdict
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        poly = defaultdict(int)
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "insert":
                coeff = int(tokens[idx+1])
                exp = int(tokens[idx+2])
                poly[exp] += coeff
                if poly[exp] == 0: del poly[exp]
                idx += 3
            elif cmd == "delete":
                exp = int(tokens[idx+1])
                if exp in poly: del poly[exp]
                idx += 2
            elif cmd == "evaluate":
                x = int(tokens[idx+1])
                ans = sum(c * (x ** e) for e, c in poly.items())
                print(ans)
                idx += 2
            elif cmd == "display":
                sorted_terms = sorted(poly.items(), key=lambda t: -t[0])
                if not sorted_terms:
                    print("0")
                else:
                    parts = [f"{c}x^{e}" if e > 0 else f"{c}" for e, c in sorted_terms]
                    print(" + ".join(parts))
                idx += 1
if __name__ == '__main__':
    main()