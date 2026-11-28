#include <stdio.h>
long long power(long long base, long long exp, long long mod) {
    long long res = 1; base %= mod;
    while(exp > 0) { if(exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; }
    return res;
}
long long phi(long long n) {
    long long res = n;
    for(long long i=2; i*i<=n; i++) { if(n % i == 0) { while(n % i == 0) n /= i; res -= res / i; } }
    if(n > 1) res -= res / n;
    return res;
}
int main() {
    long long a, n; scanf("%lld%lld", &a, &n);
    printf("%lld\n", power(a, phi(n), n));
    return 0;
}
