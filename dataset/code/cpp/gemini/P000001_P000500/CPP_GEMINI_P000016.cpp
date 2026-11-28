#include <iostream>

int main() {
    double c;
    if (std::cin >> c) {
        double f = (c * 9.0 / 5.0) + 32.0;
        std::cout << f << std::endl;
    }
    return 0;
}