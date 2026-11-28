import sys

def solve():
    n = int(sys.stdin.readline())
    if n == 2:
        print(1)
    elif n == 3:
        print(2)
    else:
        if n % 3 == 0:
            print(3 ** (n // 3))
        elif n % 3 == 1:
            print(4 * 3 ** ((n - 4) // 3))
        else:
            print(2 * 3 ** ((n - 2) // 3))

if __name__ == "__main__":
    solve()

