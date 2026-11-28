#include <vector>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        double maxSum = curSum;

        for (size_t i = k; i < nums.size(); i++) {
            curSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum / k;
    }
};