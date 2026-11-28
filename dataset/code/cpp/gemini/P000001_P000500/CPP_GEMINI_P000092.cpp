#include <iostream>
#include <iomanip>

double sumOfAP(double a, double d, int n) {
    if (n <= 0) return 0.0;
    return (n / 2.0) * (2.0 * a + (n - 1) * d);
}

int main() {
    double a, d;
    int n;
    if (std::cin >> a >> d >> n) {
        std::cout << std::fixed << std::setprecision(2) << sumOfAP(a, d, n) << "\n";
    }
    return 0;
}