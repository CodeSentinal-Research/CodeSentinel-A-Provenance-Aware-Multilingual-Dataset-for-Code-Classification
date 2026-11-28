#include <vector>
#include <algorithm>
class Solution {
public:
    int smallestSubarraySum(std::vector<int>& nums) {
        int minSum = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = std::min(nums[i], cur + nums[i]);
            minSum = std::min(minSum, cur);
        }
        return minSum;
    }
};
