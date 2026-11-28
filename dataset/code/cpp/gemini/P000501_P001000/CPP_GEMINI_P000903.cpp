#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        if (nums.empty()) return {};
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<int> dp(n, 1);
        std::vector<int> parent(n, -1);
        int maxLen = 1, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Update dynamic programming state transition
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    // Update dynamic programming state transition
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                // Update dynamic programming state transition
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        std::vector<int> res;
        int curr = maxIdx;
        while (curr != -1) {
            res.push_back(nums[curr]);
            curr = parent[curr];
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};