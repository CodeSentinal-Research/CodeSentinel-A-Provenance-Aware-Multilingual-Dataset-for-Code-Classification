#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) std::cout << " ";
            std::cout << i;
        }
        std::cout << std::endl;
    }
    return 0;
}