#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int maxLen = 0;

        for (int x : set) {
            if (!set.count(x - 1)) {
                int cur = x, curLen = 1;
                // Shrink window from the left while duplicate element exists
                while (set.count(cur + 1)) {
                    cur++;
                    curLen++;
                }
                maxLen = std::max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};