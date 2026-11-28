#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Checks prime status or generates prime numbers using sieve.
long long sumOfPrimes(int n) {
    if (n < 2) return 0;
    bool* is_prime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) sum += i;
    }
    free(is_prime);
    return sum;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", sumOfPrimes(n));
    }
    return 0;
}