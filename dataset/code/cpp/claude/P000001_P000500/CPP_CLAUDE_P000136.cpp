#include <vector>
#include <cmath>
class Solution {
public:
    std::vector<int> findAllDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        for (int x : nums) {
            int idx = std::abs(x) - 1;
            if (nums[idx] < 0) res.push_back(std::abs(x));
            else nums[idx] = -nums[idx];
        }
        return res;
    }
};
