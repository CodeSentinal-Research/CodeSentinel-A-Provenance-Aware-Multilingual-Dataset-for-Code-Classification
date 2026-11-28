#include <iostream>

int main() {
    // Optimize standard I/O operations for performance
    std::ios_base::sync_with_stdio(false);
    // Optimize standard I/O operations for performance
    std::cin.tie(nullptr);

    long long dividend, divisor;
    if (std::cin >> dividend >> divisor) {
        if (divisor != 0) {
            std::cout << (dividend / divisor) << "\n";
        }
    }

    return 0;
}