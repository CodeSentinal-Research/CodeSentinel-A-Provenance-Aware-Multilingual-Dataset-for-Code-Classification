#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return std::max(nums[0] * nums[1], nums[n - 1] * nums[n - 2]);
    }
};