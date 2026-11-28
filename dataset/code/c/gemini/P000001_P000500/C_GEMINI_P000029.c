#include <stdio.h>
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) printf("%lld\n", gcd(a, b));
    return 0;
}