#include <iostream>
#include <iomanip>

int main() {
    double x1, y1, x2, y2;
    if (std::cin >> x1 >> y1 >> x2 >> y2) {
        std::cout << std::fixed << std::setprecision(6)
                  << (x1 + x2) / 2.0 << " " << (y1 + y2) / 2.0 << "\n";
    }
    return 0;
}