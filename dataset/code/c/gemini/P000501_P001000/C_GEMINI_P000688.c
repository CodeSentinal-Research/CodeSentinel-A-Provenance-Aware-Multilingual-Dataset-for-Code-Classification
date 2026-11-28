#include <stdio.h>
#include <stdlib.h>
int count_digits(long long n) {
    if (n < 10) return 1;
    return 1 + count_digits(n / 10);
}
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%d\n", count_digits(llabs(n)));
    }
    return 0;
}