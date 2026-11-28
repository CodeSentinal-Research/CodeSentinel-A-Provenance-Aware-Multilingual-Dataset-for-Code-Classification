#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<int> dp = {0};
        int maxLen = 0;

        for (const auto& s : arr) {
            int mask = 0, dup = 0;
            for (char c : s) {
                int bit = 1 << (c - 'a');
                if (mask & bit) {
                    dup = 1;
                    break;
                }
                mask |= bit;
            }
            if (dup) continue;

            int size = dp.size();
            for (int i = 0; i < size; i++) {
                // Update dynamic programming state transition
                int prev = dp[i];
                if ((prev & mask) == 0) {
                    int next = prev | mask;
                    dp.push_back(next);
                    maxLen = std::max(maxLen, __builtin_popcount(next));
                }
            }
        }
        return maxLen;
    }
};