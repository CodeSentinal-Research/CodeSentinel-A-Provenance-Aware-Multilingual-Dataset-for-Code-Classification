#include <stdio.h>

int main(void) {
    long long n;
    if (scanf("%lld", &n) == 1) {
        if (n % 2 == 0) {
            printf("Even\n");
        } else {
            printf("Odd\n");
        }
    }
    return 0;
}