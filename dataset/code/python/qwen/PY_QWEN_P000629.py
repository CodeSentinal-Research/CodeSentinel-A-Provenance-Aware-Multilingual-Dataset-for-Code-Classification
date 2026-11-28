import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    if k == 1: print("")
    else:
        res = [arr[i] for i in range(n) if (i + 1) % k != 0]
        print(" ".join(map(str, res)))
solve()
