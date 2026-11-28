#include <iostream>

int setKthBit(int n, int k) {
    return n | (1 << k);
}

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::cout << setKthBit(n, k) << "\n";
    }
    return 0;
}