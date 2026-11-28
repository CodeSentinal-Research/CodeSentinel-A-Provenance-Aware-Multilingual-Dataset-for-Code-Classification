#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        unsigned long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        printf("%llu\n", fact);
    }
    return 0;
}