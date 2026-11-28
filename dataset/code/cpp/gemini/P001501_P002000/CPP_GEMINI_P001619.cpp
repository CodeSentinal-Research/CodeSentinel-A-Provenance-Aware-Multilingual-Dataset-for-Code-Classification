#include <iostream>
#include <vector>

int main() {
    int n, l, r;
    if (std::cin >> n >> l >> r) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (i >= l && i <= r) ans ^= x;
        }
        std::cout << ans << "\n";
    }
    return 0;
}