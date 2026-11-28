#include <stdio.h>

long long countNonPurchasable(long long a, long long b) {
    return (a - 1) * (b - 1) / 2;
}

int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", countNonPurchasable(a, b));
    }
    return 0;
}