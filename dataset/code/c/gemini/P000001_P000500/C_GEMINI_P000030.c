#include <stdio.h>
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        long long lcm = (a / gcd(a, b)) * b;
        printf("%lld\n", lcm);
    }
    return 0;
}