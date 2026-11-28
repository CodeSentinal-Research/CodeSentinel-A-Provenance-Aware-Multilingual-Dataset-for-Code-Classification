import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    a, b = int(d[0]), int(d[1])
    mask = 0xFFFFFFFF
    while b != 0:
        a, b = (a ^ b) & mask, ((a & b) << 1) & mask
    print(a if a <= 0x7FFFFFFF else ~(a ^ mask))
solve()
