import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n == 1:
        print(0)
        return
    a, b = 0, 1
    for i in range(3, n + 1):
        a, b = b, (i - 1) * (a + b)
    print(b)
solve()
