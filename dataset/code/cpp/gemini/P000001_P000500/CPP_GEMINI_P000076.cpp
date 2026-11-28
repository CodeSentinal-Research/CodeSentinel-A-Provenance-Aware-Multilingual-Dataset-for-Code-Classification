#include <iostream>
#include <cmath>
int main() {
    double a, b, c;
    if (std::cin >> a >> b >> c) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            double r1 = (-b + std::sqrt(d)) / (2 * a);
            double r2 = (-b - std::sqrt(d)) / (2 * a);
            std::cout << r1 << " " << r2 << std::endl;
        } else if (d == 0) {
            std::cout << -b / (2 * a) << std::endl;
        } else {
            std::cout << "Complex Roots" << std::endl;
        }
    }
    return 0;
}