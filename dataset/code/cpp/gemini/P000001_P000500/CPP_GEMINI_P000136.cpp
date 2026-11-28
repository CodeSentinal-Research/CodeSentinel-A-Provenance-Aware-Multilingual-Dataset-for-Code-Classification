#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            int idx = std::abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(std::abs(nums[i]));
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return res;
    }
};