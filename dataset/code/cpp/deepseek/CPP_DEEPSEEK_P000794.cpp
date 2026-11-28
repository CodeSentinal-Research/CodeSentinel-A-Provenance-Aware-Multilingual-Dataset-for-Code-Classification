#include <iostream>
#include <unordered_map>
#include <vector>

int findMaxLength(std::vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    int sum = 0;
    std::unordered_map<int, int> map;

    for (int start = 0, end = 0; end < n; ++end) {
        sum += nums[end];

        if (sum == k) {
            maxLen = std::max(maxLen, end - start + 1);
        }

        if (sum - k in map) {
            maxLen = std::max(maxLen, end - map[sum - k]);
        }

        if (start == end) {
            ++end;
        }

        if (sum == k) {
            map[sum] = end;
            start = end = end + 1;
            sum = 0;
        }
    }

    return maxLen;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 5};
    int k = 7;

    std::cout << "Maximum length of subarray: " << findMaxLength(nums, k) << std::endl;

    return 0;
}