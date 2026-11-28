#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestSumSubarray(std::vector<int>& nums) {
        int minSum = nums[0], curSum = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            curSum = std::min(nums[i], curSum + nums[i]);
            minSum = std::min(minSum, curSum);
        }
        return minSum;
    }
};