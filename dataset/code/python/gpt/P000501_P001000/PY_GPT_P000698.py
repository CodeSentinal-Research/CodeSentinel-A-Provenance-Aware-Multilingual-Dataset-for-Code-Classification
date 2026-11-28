# problem title : Fast Modular Exponentiation Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def mod_pow_rec(base, exp, mod):
    if exp == 0: return 1 % mod
    half = mod_pow_rec(base, exp // 2, mod)
    res = (half * half) % mod
    if exp % 2 != 0:
        res = (res * (base % mod)) % mod
    return res
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        base = int(tokens[0])
        exp = int(tokens[1])
        mod = int(tokens[2])
        print(mod_pow_rec(base, exp, mod))
if __name__ == '__main__':
    main()
