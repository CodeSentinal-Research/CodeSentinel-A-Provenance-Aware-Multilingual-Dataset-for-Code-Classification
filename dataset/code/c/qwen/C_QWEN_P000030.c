#include <stdio.h>

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", (a * b) / gcd(a, b));
    return 0;
}
