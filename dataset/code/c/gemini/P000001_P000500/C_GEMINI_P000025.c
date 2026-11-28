#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        long long sign = n < 0 ? -1 : 1;
        long long num = llabs(n);
        long long rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        printf("%lld\n", sign * rev);
    }
    return 0;
}