#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int maxK = -1;
        for (int x : nums) {
            if (x > 0 && set.count(-x)) {
                maxK = std::max(maxK, x);
            }
        }
        return maxK;
    }
};