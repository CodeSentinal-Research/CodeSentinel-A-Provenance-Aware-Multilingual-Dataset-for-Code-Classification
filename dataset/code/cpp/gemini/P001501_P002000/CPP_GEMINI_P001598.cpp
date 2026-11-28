#include <iostream>
#include <vector>

int main() {
    int n, l, r;
    if (std::cin >> n >> l >> r) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (i >= l && i <= r && x % 2 == 0) count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}