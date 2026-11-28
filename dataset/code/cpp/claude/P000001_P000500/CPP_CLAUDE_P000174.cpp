#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i=1;i<(int)nums.size();i++)
            minDiff = std::min(minDiff, nums[i]-nums[i-1]);
        return minDiff;
    }
};
