#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = std::max(nums[i], cur + nums[i]);
            maxSum = std::max(maxSum, cur);
        }
        return maxSum;
    }
};
