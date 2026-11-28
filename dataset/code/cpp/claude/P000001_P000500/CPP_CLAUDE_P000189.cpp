#include <vector>
#include <algorithm>
class Solution {
public:
    int maxCircularSubarraySum(std::vector<int>& nums) {
        int total=0, maxSum=nums[0], curMax=0, minSum=nums[0], curMin=0;
        for (int x : nums) {
            curMax=std::max(x, curMax+x); maxSum=std::max(maxSum, curMax);
            curMin=std::min(x, curMin+x); minSum=std::min(minSum, curMin);
            total+=x;
        }
        return maxSum > 0 ? std::max(maxSum, total-minSum) : maxSum;
    }
};
