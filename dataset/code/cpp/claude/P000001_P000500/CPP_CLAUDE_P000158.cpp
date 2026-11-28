#include <vector>
#include <algorithm>
class Solution {
public:
    long long largestSumIncreasing(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        long long best = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = (nums[i] > nums[i-1]) ? cur + nums[i] : nums[i];
            best = std::max(best, cur);
        }
        return best;
    }
};
