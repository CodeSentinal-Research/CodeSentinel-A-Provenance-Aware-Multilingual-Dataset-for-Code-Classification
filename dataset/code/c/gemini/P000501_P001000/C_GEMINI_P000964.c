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

long long crt(const long long num[], const long long rem[], int k) {
    long long prod = 1;
    for (int i = 0; i < k; i++) prod *= num[i];
    long long result = 0;
    for (int i = 0; i < k; i++) {
        long long pp = prod / num[i];
        long long x, y;
        extGcd(pp, num[i], &x, &y);
        long long inv = (x % num[i] + num[i]) % num[i];
        result = (result + rem[i] * pp % prod * inv) % prod;
    }
    return result;
}

int main() {
    int k;
    if (scanf("%d", &k) == 1 && k > 0) {
        long long num[k], rem[k];
        for (int i = 0; i < k; i++) scanf("%lld", &num[i]);
        for (int i = 0; i < k; i++) scanf("%lld", &rem[i]);
        printf("%lld\n", crt(num, rem, k));
    }
    return 0;
}