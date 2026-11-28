#include <iostream>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    // Optimize standard I/O operations for performance
    std::cin.tie(nullptr);

    long long n;
    while (std::cin >> n) {
        if (n % 2 == 0) {
            std::cout << "Even\n";
        } else {
            std::cout << "Odd\n";
        }
    }

    return 0;
}