#include <iostream>

int main() {
    int n;
    if (std::cin >> n) {
        unsigned long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        std::cout << fact << std::endl;
    }
    return 0;
}