#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        long long inc = 0, exc = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            long long newInc = exc + x;
            long long newExc = std::max(inc, exc);
            inc = newInc;
            exc = newExc;
        }
        std::cout << std::max(inc, exc) << "\n";
    }
    return 0;
}