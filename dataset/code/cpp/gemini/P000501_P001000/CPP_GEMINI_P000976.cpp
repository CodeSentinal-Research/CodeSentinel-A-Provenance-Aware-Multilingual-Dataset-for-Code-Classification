#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x1, y1, x2, y2, x3, y3;
    if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double area = 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        std::cout << std::fixed << std::setprecision(6) << area << "\n";
    }
    return 0;
}