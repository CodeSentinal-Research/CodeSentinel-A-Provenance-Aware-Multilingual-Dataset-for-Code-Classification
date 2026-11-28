#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n, l, r;
    if (std::cin >> n >> l >> r) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (i >= l && i <= r) sum += x;
        }
        std::cout << std::fixed << std::setprecision(2) << sum / (r - l + 1) << "\n";
    }
    return 0;
}