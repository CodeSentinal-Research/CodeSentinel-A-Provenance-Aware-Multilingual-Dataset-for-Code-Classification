#include <iostream>

int main() {
    int i, n;
    if (std::cin >> i >> n) {
        int l = (2 * i + 1 < n) ? 2 * i + 1 : -1;
        int r = (2 * i + 2 < n) ? 2 * i + 2 : -1;
        std::cout << l << " " << r << "\n";
    }
    return 0;
}