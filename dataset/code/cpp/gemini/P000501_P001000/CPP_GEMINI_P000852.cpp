#include <iostream>

int clearKthBit(int n, int k) {
    return n & ~(1 << k);
}

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::cout << clearKthBit(n, k) << "\n";
    }
    return 0;
}