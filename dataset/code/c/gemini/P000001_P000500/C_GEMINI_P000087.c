#include <stdio.h>

long long sumOfNaturalNumbers(long long n) {
    if (n < 0) return 0;
    return (n * (n + 1)) / 2;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%lld\n", sumOfNaturalNumbers(n));
    }
    return 0;
}