import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, target = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    def rec(i):
        if i == n: return 0
        return (1 if arr[i] == target else 0) + rec(i + 1)
    print(rec(0))
solve()
