#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return llabs(a);
}

int main() {
    long long a, b, x, y;
    if (scanf("%lld %lld %lld %lld", &a, &b, &x, &y) == 4) {
        printf("%s\n", (a * x + b * y == gcd(a, b)) ? "YES" : "NO");
    }
    return 0;
}