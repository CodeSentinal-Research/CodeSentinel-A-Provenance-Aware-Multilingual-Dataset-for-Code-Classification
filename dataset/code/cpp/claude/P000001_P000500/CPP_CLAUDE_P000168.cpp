#include <vector>
#include <algorithm>
class Solution {
public:
    int longestDecreasingSubarray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int best = 1, cur = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = (nums[i] < nums[i-1]) ? cur+1 : 1;
            best = std::max(best, cur);
        }
        return best;
    }
};
