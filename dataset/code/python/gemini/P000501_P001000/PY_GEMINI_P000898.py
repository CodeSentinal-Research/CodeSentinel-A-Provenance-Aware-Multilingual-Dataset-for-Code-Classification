import math

def reduce_fraction(num: int, den: int):
    common = math.gcd(num, den)
    return num // common, den // common

if __name__ == '__main__':
    num, den = map(int, input().split())
    n, d = reduce_fraction(num, den)
    print(f"{n} {d}")