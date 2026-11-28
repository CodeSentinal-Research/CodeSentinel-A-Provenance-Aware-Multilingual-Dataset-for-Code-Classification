#include <iostream>
#include <vector>

int main() {
    int n, x;
    if (std::cin >> n >> x) {
        long long curSum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int val;
            std::cin >> val;
            curSum += val;
            if (curSum >= x && ans == -1) {
                ans = i + 1;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}