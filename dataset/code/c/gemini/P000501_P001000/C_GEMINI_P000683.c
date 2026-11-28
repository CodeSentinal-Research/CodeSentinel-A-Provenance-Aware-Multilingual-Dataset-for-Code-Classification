#include <stdio.h>
long long power_rec(long long x, int n) {
    if (n == 0) return 1;
    long long half = power_rec(x, n / 2);
    if (n % 2 == 0) return half * half;
    return half * half * x;
}
int main() {
    long long x; int n;
    if (scanf("%lld %d", &x, &n) == 2) {
        printf("%lld\n", power_rec(x, n));
    }
    return 0;
}