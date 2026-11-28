#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        double curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        std::cout << std::fixed << std::setprecision(2) << curSum / k;

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            std::cout << " " << curSum / k;
        }
        std::cout << "\n";
    }
    return 0;
}