import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, target = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    res = []
    def rec(idx, curr, rem):
        if rem == 0:
            res.append(curr[:])
            return
        if idx == n or rem < 0: return
        curr.append(arr[idx])
        rec(idx, curr, rem - arr[idx])
        curr.pop()
        rec(idx + 1, curr, rem)
    rec(0, [], target)
    for x in sorted(res): print(" ".join(map(str, x)))
solve()
