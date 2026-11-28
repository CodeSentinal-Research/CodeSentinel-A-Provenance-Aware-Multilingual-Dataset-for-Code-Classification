#include <vector>

class Solution {
    void backtrack(const std::vector<int>& candidates, int target, int idx, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || idx == (int)candidates.size()) return;

        cur.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, cur, res);
        cur.pop_back();

        backtrack(candidates, target, idx + 1, cur, res);
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }
};