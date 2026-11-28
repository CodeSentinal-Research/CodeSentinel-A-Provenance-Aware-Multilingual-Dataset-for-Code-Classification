#include <iostream>
#include <iomanip>
int main() {
    double r;
    if (std::cin >> r) std::cout << std::fixed << std::setprecision(5) << ((4.0 / 3.0) * 3.14159 * r * r * r) << std::endl;
    return 0;
}