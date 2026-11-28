#include <iostream>

int main() {
    double l, b;
    if (std::cin >> l >> b) {
        std::cout << 2 * (l + b) << std::endl;
    }
    return 0;
}