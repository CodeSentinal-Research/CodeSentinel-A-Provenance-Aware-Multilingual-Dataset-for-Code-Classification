#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::vector<int> inc(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) inc[i] = std::max(inc[i], inc[j] + 1);
            }
        }

        std::vector<int> dec(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) dec[i] = std::max(dec[i], dec[j] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, inc[i] + dec[i] - 1);
        }
        std::cout << ans << "\n";
    }
    return 0;
}