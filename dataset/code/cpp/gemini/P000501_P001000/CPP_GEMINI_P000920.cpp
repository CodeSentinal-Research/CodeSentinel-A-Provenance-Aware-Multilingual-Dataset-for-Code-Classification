#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    long long n;
    if (std::cin >> n) {
        n = std::abs(n);
        if (n == 0) {
            std::cout << "0 0\n";
            return 0;
        }
        int minD = 9, maxD = 0;
        while (n > 0) {
            int d = n % 10;
            minD = std::min(minD, d);
            maxD = std::max(maxD, d);
            n /= 10;
        }
        std::cout << minD << " " << maxD << "\n";
    }
    return 0;
}