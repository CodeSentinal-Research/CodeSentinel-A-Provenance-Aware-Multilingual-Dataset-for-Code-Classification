#include <iostream>

int countLeafNodes(int n) {
    return (n + 1) / 2;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << countLeafNodes(n) << "\n";
    }
    return 0;
}