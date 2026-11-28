#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        for (int i = n; i >= 1; i--) {
            if (i < n) std::cout << " ";
            std::cout << i;
        }
        std::cout << std::endl;
    }
    return 0;
}