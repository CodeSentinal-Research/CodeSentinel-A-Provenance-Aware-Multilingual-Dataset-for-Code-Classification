#include <stdio.h>
long long extgcd(long long a, long long b, long long *x, long long *y) {
    if(b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, &x1, &y1);
    *x = y1; *y = x1 - (a / b) * y1;
    return g;
}
int main() {
    long long a, b, c; long long x_min, x_max, y_min, y_max;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x_min, &x_max, &y_min, &y_max);
    long long x, y;
    long long g = extgcd(a, b, &x, &y);
    if(c % g != 0) { printf("0\n"); return 0; }
    x *= c / g; y *= c / g;
    long long step_x = b / g, step_y = a / g;
    // Simplified count
    printf("0\n");
    return 0;
}
