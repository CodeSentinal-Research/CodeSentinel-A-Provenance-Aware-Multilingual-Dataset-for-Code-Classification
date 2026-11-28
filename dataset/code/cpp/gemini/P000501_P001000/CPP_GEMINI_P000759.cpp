#include <iostream>
const long long MOD = 1000000007;
// Calculates modular exponentiation (base^exp % mod) efficiently.
long long mod_pow(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    long long half = mod_pow(base, exp / 2, mod);
    long long res = (half * half) % mod;
    if (exp % 2 != 0) res = (res * base) % mod;
    return res;
}
int main() {
    long long n;
    if (std::cin >> n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;
        long long ans = (mod_pow(5, even_pos, MOD) * mod_pow(4, odd_pos, MOD)) % MOD;
        std::cout << ans << std::endl;
    }
    return 0;
}