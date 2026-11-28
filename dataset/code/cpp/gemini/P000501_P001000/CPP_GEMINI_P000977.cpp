#include <iostream>

bool areCollinear(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0;
}

int main() {
    long long x1, y1, x2, y2, x3, y3;
    if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        std::cout << (areCollinear(x1, y1, x2, y2, x3, y3) ? "YES" : "NO") << "\n";
    }
    return 0;
}