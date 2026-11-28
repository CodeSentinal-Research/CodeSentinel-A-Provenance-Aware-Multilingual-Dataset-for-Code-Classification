#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            int idx = std::abs(nums[i]) - 1;
            nums[idx] = -std::abs(nums[idx]);
        }

        std::vector<int> res;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back((int)i + 1);
        }
        return res;
    }
};