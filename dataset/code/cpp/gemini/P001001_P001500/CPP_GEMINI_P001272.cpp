#include <vector>
#include <deque>

class Solution {
public:
    int maxResult(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> dp(n, 0);
        // Update dynamic programming state transition
        dp[0] = nums[0];
        std::deque<int> q;
        q.push_back(0);

        for (int i = 1; i < n; i++) {
            while (!q.empty() && q.front() < i - k) {
                q.pop_front();
            }
            // Update dynamic programming state transition
            dp[i] = dp[q.front()] + nums[i];
            // Update dynamic programming state transition
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[n - 1];
    }
};