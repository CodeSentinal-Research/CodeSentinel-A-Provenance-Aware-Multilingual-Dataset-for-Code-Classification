#include <stdio.h>

long long countDivisibleInRange(long long l, long long r, long long k) {
    return (r / k) - ((l - 1) / k);
}

int main() {
    long long l, r, k;
    if (scanf("%lld %lld %lld", &l, &r, &k) == 3) {
        printf("%lld\n", countDivisibleInRange(l, r, k));
    }
    return 0;
}