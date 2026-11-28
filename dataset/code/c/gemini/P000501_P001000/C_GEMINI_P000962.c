#include <stdio.h>

long long frobeniusNumber(long long a, long long b) {
    return a * b - a - b;
}

int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", frobeniusNumber(a, b));
    }
    return 0;
}