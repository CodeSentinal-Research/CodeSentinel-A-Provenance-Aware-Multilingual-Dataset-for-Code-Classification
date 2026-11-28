# problem title : Binomial Coefficient Modulo Prime
# Solve the stated task using standard input and standard output.
def mod_pow(base: int, exp: int, mod: int) -> int:
    res = 1
    base %= mod
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
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
