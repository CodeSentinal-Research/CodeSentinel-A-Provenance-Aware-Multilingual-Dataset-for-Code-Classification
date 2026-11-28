#include <iostream>
#include <cmath>

int productOfDigits(int n) {
    n = std::abs(n);
    if (n == 0) return 0;
    int prod = 1;
    while (n > 0) {
        prod *= (n % 10);
        n /= 10;
    }
    return prod;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << productOfDigits(n) << "\n";
    }
    return 0;
}