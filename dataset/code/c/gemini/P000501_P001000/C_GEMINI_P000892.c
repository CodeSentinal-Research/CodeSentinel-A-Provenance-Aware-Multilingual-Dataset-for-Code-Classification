#include <stdio.h>

// Checks prime status or generates prime numbers using sieve.
void printPrimeFactors(long long n) {
    int first = 1;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            if (!first) printf(" ");
            printf("%lld", d);
            first = 0;
            n /= d;
        }
    }
    if (n > 1) {
        if (!first) printf(" ");
        printf("%lld", n);
    }
    printf("\n");
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printPrimeFactors(n);
    }
    return 0;
}