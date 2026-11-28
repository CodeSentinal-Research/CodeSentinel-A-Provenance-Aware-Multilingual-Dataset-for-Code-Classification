#include <vector>

class Solution {
    bool backtrack(int idx, int n, std::vector<int>& res, std::vector<bool>& used) {
        while (idx < (int)res.size() && res[idx] != 0) idx++;
        if (idx == (int)res.size()) return true;

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;
            if (num == 1) {
                res[idx] = 1;
                used[1] = true;
                if (backtrack(idx + 1, n, res, used)) return true;
                res[idx] = 0;
                used[1] = false;
            } else if (idx + num < (int)res.size() && res[idx + num] == 0) {
                res[idx] = num;
                res[idx + num] = num;
                used[num] = true;
                if (backtrack(idx + 1, n, res, used)) return true;
                res[idx] = 0;
                res[idx + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }
public:
    std::vector<int> constructDistancedSequence(int n) {
        std::vector<int> res(2 * n - 1, 0);
        std::vector<bool> used(n + 1, false);
        backtrack(0, n, res, used);
        return res;
    }
};