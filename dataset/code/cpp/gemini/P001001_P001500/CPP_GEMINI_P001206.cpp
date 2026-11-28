#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp = nums;

        for (int diff = 1; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                // Update dynamic programming state transition
                dp[i] = std::max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }
        // Update dynamic programming state transition
        return dp[0] >= 0;
    }
};