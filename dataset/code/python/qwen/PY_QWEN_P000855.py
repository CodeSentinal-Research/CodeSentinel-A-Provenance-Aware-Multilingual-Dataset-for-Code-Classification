import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n == 0:
        print(32)
    else:
        print(32 - n.bit_length())
solve()
