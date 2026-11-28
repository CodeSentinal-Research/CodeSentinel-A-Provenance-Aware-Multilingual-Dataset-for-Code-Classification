#include <stdio.h>
#include <stdlib.h>

void minMaxDigit(long long n) {
    n = llabs(n);
    if (n == 0) {
        printf("0 0\n");
        return;
    }
    int minD = 9, maxD = 0;
    while (n > 0) {
        int d = n % 10;
        if (d < minD) minD = d;
        if (d > maxD) maxD = d;
        n /= 10;
    }
    printf("%d %d\n", minD, maxD);
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        minMaxDigit(n);
    }
    return 0;
}