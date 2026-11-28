import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, target = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    res = []
    def rec(idx, curr, path):
        if curr == target:
            res.append(path[:])
            return
        if idx == n: return
        for i in range(idx, n):
            path.append(arr[i])
            rec(i + 1, curr + arr[i], path)
            path.pop()
    rec(0, 0, [])
    for x in res: print(" ".join(map(str, x)))
solve()
