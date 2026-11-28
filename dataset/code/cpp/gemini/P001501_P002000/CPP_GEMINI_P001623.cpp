#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        long long cur = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            cur += x;
            if (cur < 0) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}