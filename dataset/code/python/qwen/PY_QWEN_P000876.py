import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n == 0:
        print(1)
    else:
        mask = (1 << n.bit_length()) - 1
        print(n ^ mask)
solve()
