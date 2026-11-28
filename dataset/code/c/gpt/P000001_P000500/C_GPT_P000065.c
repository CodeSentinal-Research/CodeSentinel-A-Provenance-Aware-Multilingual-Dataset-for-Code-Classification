#include <stdio.h>

long long gcd(long long a, long long b) { while (b) { long long t = b; b = a % b; a = t; } return a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main(void) {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) return 1;
    printf("%lld\n", lcm(lcm(a, b), c));
    return 0;
}
