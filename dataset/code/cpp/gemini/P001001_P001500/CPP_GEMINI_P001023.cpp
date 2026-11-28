#include <iostream>

int parentIndex(int i) {
    if (i <= 0) return -1;
    return (i - 1) / 2;
}

int main() {
    int i;
    if (std::cin >> i) {
        std::cout << parentIndex(i) << "\n";
    }
    return 0;
}