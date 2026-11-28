import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, N = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    print(" ".join(map(str, [arr[i] for i in range(n) if (i + 1) % N != 0])))
solve()
