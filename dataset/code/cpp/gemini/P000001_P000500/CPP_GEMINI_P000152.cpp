#include <vector>
#include <algorithm>

class Solution {
public:
    int minProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return std::min(nums[0] * nums[n - 1], std::min(nums[0] * nums[1], nums[n - 1] * nums[n - 2]));
    }
};