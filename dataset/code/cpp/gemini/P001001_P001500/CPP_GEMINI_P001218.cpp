#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        // Update dynamic programming state transition
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    // Update dynamic programming state transition
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};