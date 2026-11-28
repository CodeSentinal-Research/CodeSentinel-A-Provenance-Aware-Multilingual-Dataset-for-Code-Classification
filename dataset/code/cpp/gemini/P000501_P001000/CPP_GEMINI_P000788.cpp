#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k; std::cin >> k;
        long long cur = 0;
        for (int i = 0; i < k; i++) cur += nums[i];
        long long max_sum = cur;
        for (int i = k; i < n; i++) {
            cur += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, cur);
        }
        std::cout << std::fixed << std::setprecision(5) << (double)max_sum / k << std::endl;
    }
    return 0;
}