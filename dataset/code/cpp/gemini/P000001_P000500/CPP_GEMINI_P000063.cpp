#include <iostream>
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
int main() {
    int l, r;
    if (std::cin >> l >> r) {
        bool first = true;
        for (int i = l; i <= r; i++) {
            if (is_prime(i)) {
                if (!first) std::cout << " ";
                std::cout << i;
                first = false;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}