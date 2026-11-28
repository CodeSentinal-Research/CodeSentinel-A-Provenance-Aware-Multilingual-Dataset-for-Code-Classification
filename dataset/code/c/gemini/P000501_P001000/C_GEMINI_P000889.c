#include <stdio.h>
#include <stdbool.h>

// Checks prime status or generates prime numbers using sieve.
bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%s\n", isPrime(n) ? "YES" : "NO");
    }
    return 0;
}