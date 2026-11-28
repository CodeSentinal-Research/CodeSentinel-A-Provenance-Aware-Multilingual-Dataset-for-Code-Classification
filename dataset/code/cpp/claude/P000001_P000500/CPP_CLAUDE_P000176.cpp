#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
    int chocolateDistribution(std::vector<int>& nums, int m) {
        if (m == 0 || nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        if (m > n) return -1;
        int minDiff = INT_MAX;
        for (int i = 0; i <= n - m; i++)
            minDiff = std::min(minDiff, nums[i + m - 1] - nums[i]);
        return minDiff;
    }
};
