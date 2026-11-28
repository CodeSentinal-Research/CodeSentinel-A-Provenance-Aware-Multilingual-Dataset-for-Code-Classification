#include <stdio.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long num, den;
    if (scanf("%lld %lld", &num, &den) == 2) {
        long long g = gcd(num, den);
        printf("%lld %lld\n", num / g, den / g);
    }
    return 0;
}