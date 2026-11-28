#include <iostream>
#include <vector>
#include <cmath>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        long long total = 0;
        for (int i = 0; i < n; i++) { std::cin >> nums[i]; total += nums[i]; }
        long long left = 0;
        for (int i = 0; i < n; i++) {
            long long right = total - left - nums[i];
            std::cout << std::abs(left - right) << (i == n - 1 ? "" : " ");
            left += nums[i];
        }
        std::cout << std::endl;
    }
    return 0;
}