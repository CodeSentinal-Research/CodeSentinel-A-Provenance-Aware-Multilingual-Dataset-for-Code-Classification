#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x1, y1, x2, y2;
    if (std::cin >> x1 >> y1 >> x2 >> y2) {
        std::cout << std::fixed << std::setprecision(6) << std::hypot(x2 - x1, y2 - y1) << "\n";
    }
    return 0;
}