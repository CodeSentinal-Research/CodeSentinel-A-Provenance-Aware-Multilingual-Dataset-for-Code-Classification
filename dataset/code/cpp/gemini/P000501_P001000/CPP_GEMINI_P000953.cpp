#include <iostream>

long long phi(long long n) {
    long long res = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

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
    long long a, b, m;
    if (std::cin >> a >> b >> m) {
        long long p = phi(m);
        long long exp = b % p;
        std::cout << modPow(a, exp, m) << "\n";
    }
    return 0;
}