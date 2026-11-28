#include <vector>
#include <numeric>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;
        std::vector<bool> dp(target + 1, false);
        // Update dynamic programming state transition
        dp[0] = true;
        for (int x : nums) {
            for (int j = target; j >= x; j--) {
                // Update dynamic programming state transition
                dp[j] = dp[j] || dp[j - x];
            }
        }
        return dp[target];
    }
};