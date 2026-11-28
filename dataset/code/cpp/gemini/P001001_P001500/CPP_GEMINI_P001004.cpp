#include <iostream>
#include <cmath>

int heapHeight(int n) {
    if (n <= 0) return 0;
    return static_cast<int>(std::log2(n));
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << heapHeight(n) << "\n";
    }
    return 0;
}