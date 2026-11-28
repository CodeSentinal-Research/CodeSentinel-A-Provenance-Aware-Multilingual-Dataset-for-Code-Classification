#include <iostream>
#include <cmath>

int countDigits(int n) {
    n = std::abs(n);
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << countDigits(n) << "\n";
    }
    return 0;
}