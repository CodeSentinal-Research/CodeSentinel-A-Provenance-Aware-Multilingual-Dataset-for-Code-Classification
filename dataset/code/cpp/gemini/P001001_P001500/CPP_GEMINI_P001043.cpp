#include <iostream>

int lastInternalNode(int n) {
    if (n <= 1) return -1;
    return n / 2 - 1;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << lastInternalNode(n) << "\n";
    }
    return 0;
}