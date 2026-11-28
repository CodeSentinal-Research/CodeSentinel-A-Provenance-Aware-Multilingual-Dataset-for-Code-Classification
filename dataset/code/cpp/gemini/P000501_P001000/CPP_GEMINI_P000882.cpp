#include <iostream>
#include <cmath>

int sumOfDigits(int n) {
    n = std::abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << sumOfDigits(n) << "\n";
    }
    return 0;
}