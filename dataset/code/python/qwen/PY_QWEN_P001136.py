import sys

def solve():
    n = int(sys.stdin.readline())
    if n == 0:
        print(0)
    elif n <= 2:
        print(1)
    else:
        a, b, c = 0, 1, 1
        for _ in range(3, n + 1):
            a, b, c = b, c, a + b + c
        print(c)

if __name__ == "__main__":
    solve()

