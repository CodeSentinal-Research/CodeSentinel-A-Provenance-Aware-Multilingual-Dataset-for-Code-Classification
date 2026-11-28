#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
        if (k == 1) return 0;
        std::sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (size_t i = 0; i + k <= nums.size(); i++) {
            minDiff = std::min(minDiff, nums[i + k - 1] - nums[i]);
        }
        return minDiff;
    }
};