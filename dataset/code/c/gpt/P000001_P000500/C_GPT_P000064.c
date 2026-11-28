#include <stdio.h>

int main(void) {
    long long a, b, x, y;
    if (scanf("%lld %lld", &a, &b) != 2) return 1;
    x = a; y = b;
    while (y != 0) { long long t = y; y = x % y; x = t; }
    long long g = x;
    printf("%lld\n", g);
    return 0;
}
