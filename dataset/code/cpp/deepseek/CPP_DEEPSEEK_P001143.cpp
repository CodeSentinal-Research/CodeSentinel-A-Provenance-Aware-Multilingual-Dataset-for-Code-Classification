#include <iostream>
#include <vector>

int targetSum(std::vector<int>& nums, int target) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (i == j) continue;
            for (int k = 0; k < nums.size(); ++k) {
                if (j == k || i == k) continue;
                if (nums[i] + nums[j] + nums[k] == target) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main() {
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    int result = targetSum(nums, target);
    std::cout << result << std::endl;
    return 0;
}