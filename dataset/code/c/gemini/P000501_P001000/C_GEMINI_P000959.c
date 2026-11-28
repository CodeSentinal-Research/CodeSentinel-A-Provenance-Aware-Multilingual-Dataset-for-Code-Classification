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

int main() {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) == 3) {
        long long x, y;
        long long g = extGcd(a, b, &x, &y);
        if (c % g != 0) {
            printf("NO\n");
        } else {
            long long factor = c / g;
            printf("YES\n%lld %lld\n", x * factor, y * factor);
        }
    }
    return 0;
}