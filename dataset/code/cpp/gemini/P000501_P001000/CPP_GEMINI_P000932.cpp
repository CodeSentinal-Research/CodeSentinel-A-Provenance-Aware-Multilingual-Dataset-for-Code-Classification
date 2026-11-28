#include <iostream>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        long long trace = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                std::cin >> val;
                if (i == j) trace += val;
            }
        }
        std::cout << trace << "\n";
    }
    return 0;
}