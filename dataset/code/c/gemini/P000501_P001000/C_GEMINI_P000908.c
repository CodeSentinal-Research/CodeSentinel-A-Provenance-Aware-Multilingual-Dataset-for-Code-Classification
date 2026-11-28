#include <stdio.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long extGcd(long long a, long long b, long long* x, long long* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extGcd(a, m, &x, &y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    long long a, m;
    if (scanf("%lld %lld", &a, &m) == 2) {
        printf("%lld\n", modInverse(a, m));
    }
    return 0;
}