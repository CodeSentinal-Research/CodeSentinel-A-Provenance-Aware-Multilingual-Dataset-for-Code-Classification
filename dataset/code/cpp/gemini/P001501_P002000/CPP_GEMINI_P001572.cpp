#include <iostream>
#include <vector>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        long long curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        int ans = curSum % 2 == 0 ? 1 : 0;

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            if (curSum % 2 == 0) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}