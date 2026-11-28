#include <stdio.h>

long long phi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%lld\n", phi(n));
    }
    return 0;
}