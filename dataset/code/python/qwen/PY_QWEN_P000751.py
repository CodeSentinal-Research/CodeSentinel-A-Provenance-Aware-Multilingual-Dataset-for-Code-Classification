import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, target = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    res = 0
    def rec(idx, curr):
        nonlocal res
        if idx == n:
            if curr == target: res += 1
            return
        rec(idx + 1, curr + arr[idx])
        rec(idx + 1, curr)
    rec(0, 0)
    print(res)
solve()
