#include <iostream>
#include <numeric>
#include <cmath>

int main() {
    long long a, b, x, y;
    if (std::cin >> a >> b >> x >> y) {
        std::cout << ((a * x + b * y == std::gcd(a, b)) ? "YES" : "NO") << "\n";
    }
    return 0;
}