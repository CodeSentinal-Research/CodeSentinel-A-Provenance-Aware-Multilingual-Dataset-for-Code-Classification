import sys
def solve():
    d = sys.stdin.read().split()
    a, b, n = int(d[0]), int(d[1]), int(d[2])
    for i in range(n // a + 1):
        if (n - i * a) % b == 0 and (n - i * a) >= 0:
            print("true")
            return
    print("false")
solve()
