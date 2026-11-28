#include <iostream>

int main() {
    // Optimize standard I/O operations for performance
    std::ios_base::sync_with_stdio(false);
    // Optimize standard I/O operations for performance
    std::cin.tie(nullptr);

    long long a = 0;
    long long b = 0;

    // Read two integers from standard input and print their sum
    if (std::cin >> a >> b) {
        std::cout << (a + b) << '\n';
    }

    return 0;
}