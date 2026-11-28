# problem title : Fast Modular Exponentiation
# Solve the stated task using standard input and standard output.
def mod_pow(base: int, exp: int, mod: int) -> int:
    res = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp //= 2
    return res

if __name__ == '__main__':
    base, exp, mod = map(int, input().split())
    print(mod_pow(base, exp, mod))
