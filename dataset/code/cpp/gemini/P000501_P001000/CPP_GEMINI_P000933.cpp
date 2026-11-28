#include <iostream>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                std::cin >> val;
                int exp = (i == j) ? 1 : 0;
                if (val != exp) ok = false;
            }
        }
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}