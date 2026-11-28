def mod_pow(base: int, exp: int, mod: int) -> int:
    """Calculates modular exponentiation (base^exp % mod) efficiently."""
    res = 1
    base %= mod
    # Binary exponentiation: process exponent bits from LSB to MSB
    while exp > 0:
        # If current bit is set, multiply base into result
        if exp % 2 == 1:
            res = (res * base) % mod
        # Square the base for the next bit
        base = (base * base) % mod
        exp //= 2
    return res

def nCr_mod(n: int, r: int, p: int) -> int:
    if r < 0 or r > n:
        return 0
    num = 1
    den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * mod_pow(den, p - 2, p)) % p

if __name__ == '__main__':
    n, r, p = map(int, input().split())
    print(nCr_mod(n, r, p))