#include <iostream>

bool isKthBitSet(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::cout << (isKthBitSet(n, k) ? "YES" : "NO") << "\n";
    }
    return 0;
}