#include <stdio.h>
#include <stdlib.h>
long long sum_digits(long long n) {
    if (n == 0) return 0;
    return (n % 10) + sum_digits(n / 10);
}
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%lld\n", sum_digits(llabs(n)));
    }
    return 0;
}