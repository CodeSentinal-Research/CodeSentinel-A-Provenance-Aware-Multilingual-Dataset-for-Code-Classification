#include <iostream>

int countInternalNodes(int n) {
    return n / 2;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << countInternalNodes(n) << "\n";
    }
    return 0;
}