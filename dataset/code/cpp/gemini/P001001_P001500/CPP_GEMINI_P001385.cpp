#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for (int x : nums) {
            int idx = std::abs(x) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }

        std::vector<int> res;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};