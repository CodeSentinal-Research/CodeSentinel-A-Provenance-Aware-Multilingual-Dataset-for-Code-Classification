#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
    int maxDifference(std::vector<int>& nums) {
        int minVal = nums[0], maxDiff = INT_MIN;
        for (int i=1;i<(int)nums.size();i++) {
            maxDiff = std::max(maxDiff, nums[i]-minVal);
            minVal = std::min(minVal, nums[i]);
        }
        return maxDiff;
    }
};
