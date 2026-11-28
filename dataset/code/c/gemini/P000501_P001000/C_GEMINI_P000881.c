#include <stdio.h>
#include <stdlib.h>

int countDigits(int n) {
    n = abs(n);
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", countDigits(n));
    }
    return 0;
}