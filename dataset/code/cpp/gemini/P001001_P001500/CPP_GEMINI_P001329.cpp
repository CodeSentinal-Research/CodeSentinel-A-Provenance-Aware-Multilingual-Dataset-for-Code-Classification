#include <vector>
#include <algorithm>

class Solution {
    void backtrack(const std::vector<int>& nums, std::vector<bool>& visited, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, visited, cur, res);
            cur.pop_back();
            visited[i] = false;
        }
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, cur, res);
        return res;
    }
};