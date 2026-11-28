#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            cur += x;
            std::cout << cur << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}