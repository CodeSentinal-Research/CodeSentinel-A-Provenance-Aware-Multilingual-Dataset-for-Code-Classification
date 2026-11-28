#include <iostream>
#include <vector>

int main() {
    int n, k, x;
    if (std::cin >> n >> k >> x) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        long long curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        int ans = curSum > x ? 1 : 0;

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            if (curSum > x) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}