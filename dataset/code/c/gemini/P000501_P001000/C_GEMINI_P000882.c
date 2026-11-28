#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int n) {
    n = abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", sumOfDigits(n));
    }
    return 0;
}