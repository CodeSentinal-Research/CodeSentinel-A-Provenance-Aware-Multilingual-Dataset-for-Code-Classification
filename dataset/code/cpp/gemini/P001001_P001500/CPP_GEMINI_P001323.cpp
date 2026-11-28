#include <vector>
#include <algorithm>

class Solution {
    void backtrack(const std::vector<int>& candidates, int target, int idx, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0) return;

        for (size_t i = idx; i < candidates.size(); i++) {
            if (i > (size_t)idx && candidates[i] == candidates[i - 1]) continue;
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }
};