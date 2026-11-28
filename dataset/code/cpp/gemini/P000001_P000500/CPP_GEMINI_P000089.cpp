#include <iostream>
#include <iomanip>
#include <cmath>

double sqrtNewton(double n) {
    if (n <= 0) return 0.0;
    if (n == 1.0) return 1.0;
    double x = n;
    double epsilon = 1e-7;
    while (true) {
        double root = 0.5 * (x + (n / x));
        if (std::abs(root - x) < epsilon) {
            return root;
        }
        x = root;
    }
}

int main() {
    double n;
    if (std::cin >> n) {
        std::cout << std::fixed << std::setprecision(6) << sqrtNewton(n) << "\n";
    }
    return 0;
}