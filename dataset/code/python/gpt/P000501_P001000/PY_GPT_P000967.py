# problem title : Earliest Timestamp from Congruences
# Solve the stated task using standard input and standard output.
from typing import List

def ext_gcd(a: int, b: int):
    if b == 0: return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def earliest_timestamp(mods: List[int], rems: List[int]) -> int:
    a1, m1 = rems[0], mods[0]
    for i in range(1, len(mods)):
        a2, m2 = rems[i], mods[i]
        g, p, q = ext_gcd(m1, m2)
        if (a2 - a1) % g != 0:
            return -1
        mod = (m1 * m2) // g
        step = (a2 - a1) // g
        k = (p * step) % (m2 // g)
        a1 = (a1 + k * m1) % mod
        m1 = mod
    return (a1 % m1 + m1) % m1

if __name__ == '__main__':
    k = int(input())
    mods = list(map(int, input().split()))
    rems = list(map(int, input().split()))
    print(earliest_timestamp(mods, rems))
