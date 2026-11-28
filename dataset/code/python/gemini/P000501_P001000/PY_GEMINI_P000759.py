import sys
MOD = 10**9 + 7
def mod_pow(base, exp, mod):
    """Calculates modular exponentiation (base^exp % mod) efficiently."""
    if exp == 0: return 1
    half = mod_pow(base, exp // 2, mod)
    res = (half * half) % mod
    if exp % 2 != 0: res = (res * base) % mod
    return res
def count_good_numbers(n):
    even_pos = (n + 1) // 2
    odd_pos = n // 2
    return (mod_pow(5, even_pos, MOD) * mod_pow(4, odd_pos, MOD)) % MOD
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(count_good_numbers(n))
if __name__ == '__main__':
    main()