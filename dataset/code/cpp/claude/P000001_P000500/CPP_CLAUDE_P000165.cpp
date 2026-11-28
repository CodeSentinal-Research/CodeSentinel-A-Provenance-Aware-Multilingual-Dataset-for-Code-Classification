#include <vector>
#include <algorithm>
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int best = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int x = nums[i];
            int newMax = std::max({x, curMax*x, curMin*x});
            curMin = std::min({x, curMax*x, curMin*x});
            curMax = newMax;
            best = std::max(best, curMax);
        }
        return best;
    }
};
