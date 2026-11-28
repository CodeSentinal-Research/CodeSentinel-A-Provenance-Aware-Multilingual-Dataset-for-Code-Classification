#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long long sumOfPrimes(int n) {
    if (n < 2) return 0;
    bool* isPrime = (bool*)malloc((n + 1) * sizeof(bool));
    memset(isPrime, true, (n + 1) * sizeof(bool));
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) sum += i;
    }
    free(isPrime);
    return sum;
}
