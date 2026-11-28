#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if ((total + target) % 2 != 0 || total < std::abs(target)) return 0;
        int s1 = (total + target) / 2;
        std::vector<int> dp(s1 + 1, 0);
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int x : nums) {
            for (int j = s1; j >= x; j--) {
                // Update dynamic programming state transition
                dp[j] += dp[j - x];
            }
        }
        return dp[s1];
    }
};