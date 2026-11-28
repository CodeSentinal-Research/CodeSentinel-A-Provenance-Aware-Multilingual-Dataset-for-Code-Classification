#include <iostream>
#include <iomanip>
int main() {
    double r, h;
    if (std::cin >> r >> h) std::cout << std::fixed << std::setprecision(5) << (3.14159 * r * r * h) << std::endl;
    return 0;
}