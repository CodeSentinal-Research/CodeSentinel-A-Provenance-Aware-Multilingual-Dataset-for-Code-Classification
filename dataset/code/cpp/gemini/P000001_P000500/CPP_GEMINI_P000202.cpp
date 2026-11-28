#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int x : s) {
            if (!s.count(x - 1)) {
                int cur = x;
                int streak = 1;
                while (s.count(cur + 1)) {
                    cur++;
                    streak++;
                }
                longest = std::max(longest, streak);
            }
        }
        return longest;
    }
};