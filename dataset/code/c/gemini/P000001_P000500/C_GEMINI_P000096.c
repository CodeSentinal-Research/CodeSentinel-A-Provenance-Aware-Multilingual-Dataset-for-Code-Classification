#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSpyNumber(int n) {
    n = abs(n);
    int sum = 0;
    int prod = 1;
    while (n > 0) {
        int d = n % 10;
        sum += d;
        prod *= d;
        n /= 10;
    }
    return sum == prod;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%s\n", isSpyNumber(n) ? "YES" : "NO");
    }
    return 0;
}