#include <stdio.h>

// Calculates modular exponentiation (base^exp % mod) efficiently.
long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    // Binary exponentiation: process exponent bits from LSB to MSB
    while (exp > 0) {
        // If current bit is set, multiply base into result
        if (exp % 2 == 1) res = (res * base) % mod;
        // Square the base for the next bit
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long nCrMod(int n, int r, int p) {
    if (r < 0 || r > n) return 0;
    long long num = 1, den = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n - i)) % p;
        den = (den * (i + 1)) % p;
    }
    return (num * modPow(den, p - 2, p)) % p;
}

int main() {
    int n, r, p;
    if (scanf("%d %d %d", &n, &r, &p) == 3) {
        printf("%lld\n", nCrMod(n, r, p));
    }
    return 0;
}