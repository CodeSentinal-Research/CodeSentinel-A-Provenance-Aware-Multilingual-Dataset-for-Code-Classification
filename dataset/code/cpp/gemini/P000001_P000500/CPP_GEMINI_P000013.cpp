#include <iostream>
#include <iomanip>

int main() {
    double r;
    if (std::cin >> r) {
        double pi = 3.14159;
        double area = pi * r * r;
        std::cout << std::fixed << std::setprecision(5) << area << std::endl;
    }
    return 0;
}