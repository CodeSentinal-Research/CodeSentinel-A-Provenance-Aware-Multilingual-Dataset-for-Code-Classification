#include <iostream>

int main() {
    double f;
    if (std::cin >> f) {
        double c = (f - 32.0) * 5.0 / 9.0;
        std::cout << c << std::endl;
    }
    return 0;
}