#include <stdio.h>
long long extgcd(long long a, long long b, long long *x, long long *y) {
    if(b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, &x1, &y1);
    *x = y1; *y = x1 - (a / b) * y1;
    return g;
}
int main() {
    long long a, m, b, n; scanf("%lld%lld%lld%lld", &a, &m, &b, &n);
    long long p, q;
    long long g = extgcd(m, n, &p, &q);
    if((b - a) % g != 0) printf("-1\n");
    else {
        long long lcm = m / g * n;
        long long diff = (b - a) / g;
        long long x = (a + m * ((diff * p) % (n / g))) % lcm;
        if(x < 0) x += lcm;
        printf("%lld %lld\n", x, lcm);
    }
    return 0;
}
