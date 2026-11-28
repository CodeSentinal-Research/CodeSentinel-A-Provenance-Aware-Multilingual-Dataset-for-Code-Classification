#include <iostream>

int toggleKthBit(int n, int k) {
    return n ^ (1 << k);
}

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::cout << toggleKthBit(n, k) << "\n";
    }
    return 0;
}