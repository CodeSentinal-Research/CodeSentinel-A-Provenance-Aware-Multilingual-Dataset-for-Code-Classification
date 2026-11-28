#include <iostream>

int main() {
    int s, n, m;
    if (std::cin >> s >> n >> m) {
        int totalFood = s * m;
        if ((n - m) * 6 < m && s > 6) {
            std::cout << -1 << "\n";
        } else if (m > n) {
            std::cout << -1 << "\n";
        } else {
            std::cout << (totalFood + n - 1) / n << "\n";
        }
    }
    return 0;
}