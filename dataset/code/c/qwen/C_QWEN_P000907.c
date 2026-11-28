#include <stdio.h>
long long power(long long base, long long exp, long long mod) {
    long long res = 1; base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod; exp /= 2;
    }
    return res;
}
int main() {
    long long a, b, m; scanf("%lld%lld%lld", &a, &b, &m);
    printf("%lld\n", power(a, b, m));
    return 0;
}
