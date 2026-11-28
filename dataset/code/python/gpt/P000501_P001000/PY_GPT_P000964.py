# problem title : Chinese Remainder Theorem Solver
# Solve the stated task using standard input and standard output.
from typing import List

def ext_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def crt(num: List[int], rem: List[int]) -> int:
    prod = 1
    for n in num:
        prod *= n
    
    result = 0
    for n, r in zip(num, rem):
        pp = prod // n
        _, inv, _ = ext_gcd(pp, n)
        inv = (inv % n + n) % n
        result = (result + r * pp * inv) % prod
    return result

if __name__ == '__main__':
    k = int(input())
    num = list(map(int, input().split()))
    rem = list(map(int, input().split()))
    print(crt(num, rem))
