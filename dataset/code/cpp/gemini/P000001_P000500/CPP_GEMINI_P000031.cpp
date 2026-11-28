#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        bool first = true;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (!first) std::cout << " ";
                std::cout << i;
                first = false;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}