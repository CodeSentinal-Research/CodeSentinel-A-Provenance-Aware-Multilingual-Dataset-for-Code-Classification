#include <iostream>

long long countNonPurchasable(long long a, long long b) {
    return (a - 1) * (b - 1) / 2;
}

int main() {
    long long a, b;
    if (std::cin >> a >> b) {
        std::cout << countNonPurchasable(a, b) << "\n";
    }
    return 0;
}