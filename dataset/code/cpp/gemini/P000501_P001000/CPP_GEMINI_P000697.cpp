#include <iostream>
bool is_prime_rec(long long n, long long d = 2) {
    if (n <= 1) return false;
    if (d * d > n) return true;
    if (n % d == 0) return false;
    return is_prime_rec(n, d + 1);
}
int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << (is_prime_rec(n) ? "true" : "false") << std::endl;
    }
    return 0;
}