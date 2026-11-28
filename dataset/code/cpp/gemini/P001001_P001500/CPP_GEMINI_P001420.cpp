#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int difference) {
        std::unordered_map<int, int> dp;
        int maxLen = 0;

        for (int x : arr) {
            // Update dynamic programming state transition
            int len = dp[x - difference] + 1;
            // Update dynamic programming state transition
            dp[x] = len;
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};