#include <iostream>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            std::cout << x << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}