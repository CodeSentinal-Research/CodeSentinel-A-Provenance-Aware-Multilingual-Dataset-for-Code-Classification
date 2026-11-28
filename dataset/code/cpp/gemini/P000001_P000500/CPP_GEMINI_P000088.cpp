#include <iostream>
#include <cmath>
int main() {
    long long n;
    if (std::cin >> n) {
        if (n < 0) { std::cout << "Not Perfect Square" << std::endl; return 0; }
        long long sq = (long long) std::sqrt(n);
        std::cout << (sq * sq == n ? "Perfect Square" : "Not Perfect Square") << std::endl;
    }
    return 0;
}