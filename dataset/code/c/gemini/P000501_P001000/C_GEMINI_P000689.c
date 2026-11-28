#include <stdio.h>
#include <stdlib.h>
long long prod_digits(long long n) {
    if (n < 10) return n;
    return (n % 10) * prod_digits(n / 10);
}
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%lld\n", prod_digits(llabs(n)));
    }
    return 0;
}