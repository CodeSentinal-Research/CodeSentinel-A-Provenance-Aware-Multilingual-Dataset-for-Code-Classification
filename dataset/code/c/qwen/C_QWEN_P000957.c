#include <stdio.h>
long long extgcd(long long a, long long b, long long *x, long long *y) {
    if(b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, &x1, &y1);
    *x = y1; *y = x1 - (a / b) * y1;
    return g;
}
int main() {
    long long a, b, x, y; scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
    long long x1, y1;
    long long g = extgcd(a, b, &x1, &y1);
    printf("%s\n", a * x + b * y == g ? "true" : "false");
    return 0;
}
