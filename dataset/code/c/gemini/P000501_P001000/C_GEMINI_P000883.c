#include <stdio.h>
#include <stdlib.h>

int productOfDigits(int n) {
    n = abs(n);
    if (n == 0) return 0;
    int prod = 1;
    while (n > 0) {
        prod *= (n % 10);
        n /= 10;
    }
    return prod;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", productOfDigits(n));
    }
    return 0;
}