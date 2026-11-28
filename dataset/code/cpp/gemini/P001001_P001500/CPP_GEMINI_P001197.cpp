#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::unordered_map<long long, int>> dp(n);
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                // Update dynamic programming state transition
                int count = dp[j].count(diff) ? dp[j][diff] : 0;
                total += count;
                // Update dynamic programming state transition
                dp[i][diff] += count + 1;
            }
        }
        return total;
    }
};