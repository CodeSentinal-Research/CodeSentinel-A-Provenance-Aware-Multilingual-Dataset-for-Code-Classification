#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%llo %llX\n", n, n);
    }
    return 0;
}