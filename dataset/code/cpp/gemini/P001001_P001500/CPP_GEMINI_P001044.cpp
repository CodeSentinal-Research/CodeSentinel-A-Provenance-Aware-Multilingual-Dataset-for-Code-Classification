#include <iostream>
#include <cmath>

int nodeLevel(int idx) {
    return static_cast<int>(std::log2(idx + 1));
}

int main() {
    int idx;
    if (std::cin >> idx) {
        std::cout << nodeLevel(idx) << "\n";
    }
    return 0;
}