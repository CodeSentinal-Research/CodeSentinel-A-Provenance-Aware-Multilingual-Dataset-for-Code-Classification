#include <stdio.h>
long long power(long long base, long long exp, long long mod) {
    long long res = 1; base %= mod;
    while(exp > 0) { if(exp % 2 == 1) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; }
    return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
int main() {
    int n, r; long long p; scanf("%d%d%lld", &n, &r, &p);
    long long num = 1, den = 1;
    for(int i=0; i<r; i++) { num = (num * (n - i)) % p; den = (den * (i + 1)) % p; }
    printf("%lld\n", (num * modInverse(den, p)) % p);
    return 0;
}
