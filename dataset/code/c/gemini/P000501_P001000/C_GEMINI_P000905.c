#include <stdio.h>

long long modSub(long long a, long long b, long long m) {
    return ((a % m) - (b % m) + m) % m;
}

int main() {
    long long a, b, m;
    if (scanf("%lld %lld %lld", &a, &b, &m) == 3) {
        printf("%lld\n", modSub(a, b, m));
    }
    return 0;
}