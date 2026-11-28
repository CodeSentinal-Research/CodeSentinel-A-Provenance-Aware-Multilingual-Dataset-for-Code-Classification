import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    a, b, c = int(d[0]), int(d[1]), int(d[2])
    flips = 0
    for i in range(32):
        bit_a = (a >> i) & 1
        bit_b = (b >> i) & 1
        bit_c = (c >> i) & 1
        if bit_c == 0:
            flips += bit_a + bit_b
        else:
            if bit_a == 0 and bit_b == 0:
                flips += 1
    print(flips)
solve()
