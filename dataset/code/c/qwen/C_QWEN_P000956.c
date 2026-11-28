#include <stdio.h>
long long extgcd(long long a, long long b, long long *x, long long *y) {
    if(b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, &x1, &y1);
    *x = y1; *y = x1 - (a / b) * y1;
    return g;
}
int main() {
    long long a, b, m; scanf("%lld%lld%lld", &a, &b, &m);
    long long x, y;
    long long g = extgcd(a, m, &x, &y);
    if(b % g != 0) printf("-1\n");
    else {
        x = (x * (b / g)) % m;
        x = (x % (m / g) + m / g) % (m / g);
        printf("%lld\n", x);
    }
    return 0;
}
