#include <iostream>
int main() {
    double a, b, c;
    if (std::cin >> a >> b >> c) {
        std::cout << (a + b + c) / 3.0 << std::endl;
    }
    return 0;
}