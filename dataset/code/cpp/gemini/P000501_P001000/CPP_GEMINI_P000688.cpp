#include <iostream>
#include <cmath>
int count_digits(long long n) {
    if (n < 10) return 1;
    return 1 + count_digits(n / 10);
}
int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << count_digits(std::abs(n)) << std::endl;
    }
    return 0;
}