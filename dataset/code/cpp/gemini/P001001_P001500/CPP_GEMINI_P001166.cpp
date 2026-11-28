#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for (int x : nums) {
            currMax = std::max(x, currMax + x);
            maxSum = std::max(maxSum, currMax);
            currMin = std::min(x, currMin + x);
            minSum = std::min(minSum, currMin);
            totalSum += x;
        }

        return maxSum > 0 ? std::max(maxSum, totalSum - minSum) : maxSum;
    }
};