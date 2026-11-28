#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", lcm(a, lcm(b, c)));
    return 0;
}
