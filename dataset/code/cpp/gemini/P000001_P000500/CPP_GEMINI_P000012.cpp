#include <iostream>
#include <iomanip>

int main() {
    double p, r, t;
    if (std::cin >> p >> r >> t) {
        double si = (p * r * t) / 100.0;
        std::cout << si << std::endl;
    }
    return 0;
}