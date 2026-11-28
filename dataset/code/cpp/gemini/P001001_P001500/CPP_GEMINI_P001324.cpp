#include <vector>

class Solution {
    void backtrack(int start, int k, int n, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if ((int)cur.size() == k) {
            if (n == 0) res.push_back(cur);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > n) break;
            cur.push_back(i);
            backtrack(i + 1, k, n - i, cur, res);
            cur.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(1, k, n, cur, res);
        return res;
    }
};