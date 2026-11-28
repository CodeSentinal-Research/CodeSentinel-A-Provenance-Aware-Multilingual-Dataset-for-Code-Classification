#include <vector>

class Solution {
    void backtrack(const std::vector<int>& nums, int idx, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if (idx == (int)nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        backtrack(nums, idx + 1, cur, res);
        cur.pop_back();

        backtrack(nums, idx + 1, cur, res);
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(nums, 0, cur, res);
        return res;
    }
};