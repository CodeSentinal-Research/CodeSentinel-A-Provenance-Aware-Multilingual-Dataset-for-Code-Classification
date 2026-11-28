#include <iostream>
long long mod_pow_rec(long long base, long long exp, long long mod) {
    if (exp == 0) return 1 % mod;
    long long half = mod_pow_rec(base, exp / 2, mod);
    long long res = (half * half) % mod;
    if (exp % 2 != 0) res = (res * (base % mod)) % mod;
    return res;
}
int main() {
    long long base, exp, mod;
    if (std::cin >> base >> exp >> mod) {
        std::cout << mod_pow_rec(base, exp, mod) << std::endl;
    }
    return 0;
}