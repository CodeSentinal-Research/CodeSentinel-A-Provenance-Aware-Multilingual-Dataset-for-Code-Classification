#include <iostream>

int main() {
    // Optimize standard I/O operations for competitive programming
    std::ios_base::sync_with_stdio(false);
    // Optimize standard I/O operations for performance
    std::cin.tie(nullptr);

    int t;
    if (std::cin >> t) {
        while (t--) {
            int a, b;
            std::cin >> a >> b;
            std::cout << (a % b) << "\n";
        }
    }

    return 0;
}