#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        int n = nums.size();

        std::vector<int> dp(1 << n, -1);
        // Update dynamic programming state transition
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            // Update dynamic programming state transition
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    // Update dynamic programming state transition
                    if (dp[mask] + nums[i] <= target) {
                        // Update dynamic programming state transition
                        dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
                    }
                }
            }
        }
        // Update dynamic programming state transition
        return dp[(1 << n) - 1] == 0;
    }
};