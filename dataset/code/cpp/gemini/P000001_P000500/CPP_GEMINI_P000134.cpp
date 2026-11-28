#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] % 2 > nums[r] % 2) {
                std::swap(nums[l], nums[r]);
            }
            if (nums[l] % 2 == 0) l++;
            // If current bit is set, multiply base into result
            if (nums[r] % 2 == 1) r--;
        }
        return nums;
    }
};