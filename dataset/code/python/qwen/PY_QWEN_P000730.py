import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = []
    def rec(row, cols, d1, d2):
        if row == n:
            res.append(["." * c + "Q" + "." * (n - c - 1) for c in cols])
            return
        for i in range(n):
            if i in cols or (row - i) in d1 or (row + i) in d2: continue
            rec(row + 1, cols + [i], d1 + [row - i], d2 + [row + i])
    rec(0, [], [], [])
    for b in res:
        for r in b: print(r)
        print()
solve()
