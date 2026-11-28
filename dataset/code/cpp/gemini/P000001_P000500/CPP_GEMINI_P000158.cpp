#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxIncreasingSubarraySum(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        long long maxSum = nums[0], curSum = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curSum += nums[i];
            } else {
                curSum = nums[i];
            }
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum;
    }
};