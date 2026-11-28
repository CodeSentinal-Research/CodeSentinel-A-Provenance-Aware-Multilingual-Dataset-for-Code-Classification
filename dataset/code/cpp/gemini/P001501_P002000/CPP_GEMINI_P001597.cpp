#include <iostream>
#include <vector>

int main() {
    int n, l, r, x;
    if (std::cin >> n >> l >> r >> x) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int val;
            std::cin >> val;
            if (i >= l && i <= r && val == x) count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}