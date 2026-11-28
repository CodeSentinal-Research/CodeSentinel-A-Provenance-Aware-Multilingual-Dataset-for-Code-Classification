#include <stdio.h>

int countTrailingZeros(unsigned int n) {
    if (n == 0) return 32;
    return __builtin_ctz(n);
}

int main() {
    unsigned int n;
    if (scanf("%u", &n) == 1) {
        printf("%d\n", countTrailingZeros(n));
    }
    return 0;
}