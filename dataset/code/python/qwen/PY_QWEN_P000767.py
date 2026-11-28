import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    def rec(l, r):
        if l > r: return [None]
        res = []
        for i in range(l, r + 1):
            for left in rec(l, i - 1):
                for right in rec(i + 1, r):
                    res.append((i, left, right))
        return res
    trees = rec(1, N)
    for t in trees: print(t)
solve()
