def mod_pow(base: int, exp: int, mod: int) -> int:
    """Calculates modular exponentiation (base^exp % mod) efficiently."""
    res = 1
    base = base % mod
    # Binary exponentiation: process exponent bits from LSB to MSB
    while exp > 0:
        # If current bit is set, multiply base into result
        if exp % 2 == 1:
            res = (res * base) % mod
        # Square the base for the next bit
        base = (base * base) % mod
        exp //= 2
    return res

if __name__ == '__main__':
    base, exp, mod = map(int, input().split())
    print(mod_pow(base, exp, mod))