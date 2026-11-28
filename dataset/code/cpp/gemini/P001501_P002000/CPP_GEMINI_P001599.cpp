#include <iostream>
#include <vector>

int main() {
    int n, l, r, k;
    if (std::cin >> n >> l >> r >> k) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (i >= l && i <= r && x % k == 0) count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}