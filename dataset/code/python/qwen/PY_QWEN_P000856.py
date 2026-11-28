import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n == 0:
        print(0)
    else:
        print((n & -n).bit_length() - 1)
solve()
