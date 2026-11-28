#include <vector>

class Solution {
    void backtrack(int start, int n, int k, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if ((int)cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            backtrack(i + 1, n, k, cur, res);
            cur.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        backtrack(1, n, k, cur, res);
        return res;
    }
};