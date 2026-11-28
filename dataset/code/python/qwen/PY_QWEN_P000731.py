import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = 0
    def rec(row, cols, d1, d2):
        nonlocal res
        if row == n:
            res += 1
            return
        for i in range(n):
            if i in cols or (row - i) in d1 or (row + i) in d2: continue
            rec(row + 1, cols | {i}, d1 | {row - i}, d2 | {row + i})
    rec(0, set(), set(), set())
    print(res)
solve()
