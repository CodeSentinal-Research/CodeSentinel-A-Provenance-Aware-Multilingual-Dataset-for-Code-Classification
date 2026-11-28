#include <stdio.h>
long long mod_pow_rec(long long base, long long exp, long long mod) {
    if (exp == 0) return 1 % mod;
    long long half = mod_pow_rec(base, exp / 2, mod);
    long long res = (half * half) % mod;
    if (exp % 2 != 0) res = (res * (base % mod)) % mod;
    return res;
}
int main() {
    long long base, exp, mod;
    if (scanf("%lld %lld %lld", &base, &exp, &mod) == 3) {
        printf("%lld\n", mod_pow_rec(base, exp, mod));
    }
    return 0;
}