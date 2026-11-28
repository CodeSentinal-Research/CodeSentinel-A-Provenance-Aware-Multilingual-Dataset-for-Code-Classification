#include <stdio.h>
long long extgcd(long long a, long long b, long long *x, long long *y) {
    if(b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, &x1, &y1);
    *x = y1; *y = x1 - (a / b) * y1;
    return g;
}
int main() {
    int n; scanf("%d", &n);
    long long rem[n], mod[n];
    for(int i=0; i<n; i++) scanf("%lld", &rem[i]);
    for(int i=0; i<n; i++) scanf("%lld", &mod[i]);
    long long x = rem[0], m = mod[0];
    for(int i=1; i<n; i++) {
        long long p, q;
        extgcd(m, mod[i], &p, &q);
        long long diff = rem[i] - x;
        long long lcm = m / 1 * mod[i];
        x = (x + m * ((diff / 1 * p) % mod[i])) % lcm;
        if(x < 0) x += lcm;
        m = lcm;
    }
    printf("%lld\n", x);
    return 0;
}
