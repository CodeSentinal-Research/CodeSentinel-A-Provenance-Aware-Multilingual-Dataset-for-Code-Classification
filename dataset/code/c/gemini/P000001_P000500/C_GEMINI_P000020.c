#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        long long total = n * (n + 1) / 2;
        printf("%lld\n", total);
    }
    return 0;
}