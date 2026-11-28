#include <vector>
#include <algorithm>

class Solution {
    void backtrack(int first, std::vector<int>& nums, std::vector<std::vector<int>>& res) {
        if (first == (int)nums.size()) {
            res.push_back(nums);
            return;
        }
        for (size_t i = first; i < nums.size(); i++) {
            std::swap(nums[first], nums[i]);
            backtrack(first + 1, nums, res);
            std::swap(nums[first], nums[i]);
        }
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(0, nums, res);
        return res;
    }
};