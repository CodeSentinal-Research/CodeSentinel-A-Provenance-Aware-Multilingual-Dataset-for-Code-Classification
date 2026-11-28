#include <iostream>
#include <iomanip>
int main() {
    double r;
    if (std::cin >> r) std::cout << std::fixed << std::setprecision(5) << (2 * 3.14159 * r) << std::endl;
    return 0;
}