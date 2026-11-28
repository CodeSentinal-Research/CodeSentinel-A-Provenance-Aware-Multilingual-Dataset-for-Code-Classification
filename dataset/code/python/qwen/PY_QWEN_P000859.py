import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = 0
    for _ in range(32):
        res = (res << 1) | (n & 1)
        n >>= 1
    print(res)
solve()
