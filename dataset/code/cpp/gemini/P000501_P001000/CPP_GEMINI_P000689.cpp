#include <iostream>
#include <cmath>
long long prod_digits(long long n) {
    if (n < 10) return n;
    return (n % 10) * prod_digits(n / 10);
}
int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << prod_digits(std::abs(n)) << std::endl;
    }
    return 0;
}