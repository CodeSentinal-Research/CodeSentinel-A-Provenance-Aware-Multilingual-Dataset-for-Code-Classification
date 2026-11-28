#include <iostream>
#include <cmath>

bool isSpyNumber(int n) {
    n = std::abs(n);
    int sum = 0;
    int prod = 1;
    while (n > 0) {
        int d = n % 10;
        sum += d;
        prod *= d;
        n /= 10;
    }
    return sum == prod;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << (isSpyNumber(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}