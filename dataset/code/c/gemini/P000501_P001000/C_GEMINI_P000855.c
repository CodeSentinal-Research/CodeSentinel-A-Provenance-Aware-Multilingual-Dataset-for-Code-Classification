#include <stdio.h>

int countLeadingZeros(unsigned int n) {
    if (n == 0) return 32;
    return __builtin_clz(n);
}

int main() {
    unsigned int n;
    if (scanf("%u", &n) == 1) {
        printf("%d\n", countLeadingZeros(n));
    }
    return 0;
}