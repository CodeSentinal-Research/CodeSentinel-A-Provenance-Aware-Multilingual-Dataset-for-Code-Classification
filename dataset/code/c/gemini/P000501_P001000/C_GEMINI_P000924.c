#include <stdio.h>

void decimalToBinary(unsigned long long n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    char buf[65];
    int idx = 0;
    while (n > 0) {
        buf[idx++] = (n % 2) + '0';
        n /= 2;
    }
    for (int i = idx - 1; i >= 0; i--) {
        putchar(buf[i]);
    }
    putchar('\n');
}

int main() {
    unsigned long long n;
    if (scanf("%llu", &n) == 1) {
        decimalToBinary(n);
    }
    return 0;
}