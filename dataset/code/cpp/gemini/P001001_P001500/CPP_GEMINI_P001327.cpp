#include <vector>
#include <algorithm>

class Solution {
    void backtrack(const std::vector<int>& nums, int idx, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        res.push_back(cur);
        for (size_t i = idx; i < nums.size(); i++) {
            if (i > (size_t)idx && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(nums, 0, cur, res);
        return res;
    }
};