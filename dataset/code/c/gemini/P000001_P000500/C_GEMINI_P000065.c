#include <stdio.h>
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
// Computes the Least Common Multiple (LCM).
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) == 3) {
        printf("%lld\n", lcm(lcm(a, b), c));
    }
    return 0;
}