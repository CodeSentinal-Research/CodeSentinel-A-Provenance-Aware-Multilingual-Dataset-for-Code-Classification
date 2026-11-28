#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int x : nums) {
            curMax = std::max(x, curMax + x);
            maxSum = std::max(maxSum, curMax);

            curMin = std::min(x, curMin + x);
            minSum = std::min(minSum, curMin);

            total += x;
        }

        return maxSum < 0 ? maxSum : std::max(maxSum, total - minSum);
    }
};