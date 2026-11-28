#include <iostream>
#include <vector>
#include <numeric>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        long long total = 0;
        for (int i = 0; i < n; i++) { std::cin >> nums[i]; total += nums[i]; }
        long long left_sum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (left_sum == total - left_sum - nums[i]) {
                ans = i;
                break;
            }
            left_sum += nums[i];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}