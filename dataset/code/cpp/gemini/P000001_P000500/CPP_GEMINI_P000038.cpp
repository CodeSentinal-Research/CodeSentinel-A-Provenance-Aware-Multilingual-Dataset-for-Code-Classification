#include <iostream>
#include <cmath>
int main() {
    double p, r, t;
    if (std::cin >> p >> r >> t) {
        double a = p * std::pow(1.0 + r / 100.0, t);
        double ci = a - p;
        std::cout << ci << std::endl;
    }
    return 0;
}