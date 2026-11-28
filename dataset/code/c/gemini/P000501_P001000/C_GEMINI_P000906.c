#include <stdio.h>

long long modMul(long long a, long long b, long long m) {
    return ((a % m) * (b % m)) % m;
}

int main() {
    long long a, b, m;
    if (scanf("%lld %lld %lld", &a, &b, &m) == 3) {
        printf("%lld\n", modMul(a, b, m));
    }
    return 0;
}