import sys
def solve():
    target = int(sys.stdin.read().split()[0])
    res = []
    def rec(curr, rem):
        if rem == 0:
            res.append(curr[:])
            return
        for i in range(1, 7):
            if i <= rem:
                curr.append(i)
                rec(curr, rem - i)
                curr.pop()
    rec([], target)
    for x in res: print(" ".join(map(str, x)))
solve()
