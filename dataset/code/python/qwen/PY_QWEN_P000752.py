import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, target = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    res = []
    def rec(idx, curr):
        if curr == target: return True
        if idx == n or curr > target: return False
        for i in range(idx, n):
            curr += arr[i]
            res.append(arr[i])
            if rec(i + 1, curr): return True
            curr -= arr[i]
            res.pop()
        return False
    if rec(0, 0): print(" ".join(map(str, res)))
    else: print("-1")
solve()
