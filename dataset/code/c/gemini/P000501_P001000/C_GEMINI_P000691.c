#include <stdio.h>
long long gcd_rec(long long a, long long b) {
    if (b == 0) return a;
    return gcd_rec(b, a % b);
}
int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", gcd_rec(a, b));
    }
    return 0;
}