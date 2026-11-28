#include <iostream>
#include <cmath>
long long sum_digits(long long n) {
    if (n == 0) return 0;
    return (n % 10) + sum_digits(n / 10);
}
int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << sum_digits(std::abs(n)) << std::endl;
    }
    return 0;
}