#include <stdio.h>
#include <stdlib.h>
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        n = llabs(n);
        int count = 0;
        do {
            count++;
            n /= 10;
        } while (n > 0);
        printf("%d\n", count);
    }
    return 0;
}