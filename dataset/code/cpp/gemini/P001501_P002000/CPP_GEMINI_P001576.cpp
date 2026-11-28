#include <iostream>
#include <vector>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int zeros = 0;
        for (int i = 0; i < k; i++) if (nums[i] == 0) zeros++;
        int ans = zeros > 0 ? 1 : 0;

        for (int i = k; i < n; i++) {
            if (nums[i] == 0) zeros++;
            if (nums[i - k] == 0) zeros--;
            if (zeros > 0) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}