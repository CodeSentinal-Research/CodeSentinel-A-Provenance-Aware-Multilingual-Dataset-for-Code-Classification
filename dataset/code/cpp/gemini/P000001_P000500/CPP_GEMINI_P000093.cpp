#include <iostream>
#include <iomanip>
#include <cmath>

double sumOfGP(double a, double r, int n) {
    if (n <= 0) return 0.0;
    if (r == 1.0) return a * n;
    return a * (1.0 - std::pow(r, n)) / (1.0 - r);
}

int main() {
    double a, r;
    int n;
    if (std::cin >> a >> r >> n) {
        std::cout << std::fixed << std::setprecision(2) << sumOfGP(a, r, n) << "\n";
    }
    return 0;
}