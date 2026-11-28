#include <stdio.h>

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) {
        return 1;
    }

    printf("%lld\n", n * (n + 1) / 2);

    return 0;
}
