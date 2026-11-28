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

int main() {
    long long base, exp, mod;
    if (scanf("%lld %lld %lld", &base, &exp, &mod) == 3) {
        printf("%lld\n", modPow(base, exp, mod));
    }
    return 0;
}