#include <vector>
#include <algorithm>

class Solution {
    int robRange(const std::vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; i++) {
            int tmp = std::max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return std::max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};