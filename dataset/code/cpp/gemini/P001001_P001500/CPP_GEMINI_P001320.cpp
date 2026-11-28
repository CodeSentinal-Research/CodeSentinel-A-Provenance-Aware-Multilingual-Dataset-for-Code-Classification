#include <vector>
#include <string>

class Solution {
    void backtrack(int open, int close, int n, std::string cur, std::vector<std::string>& res) {
        if ((int)cur.length() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (open < n) {
            backtrack(open + 1, close, n, cur + "(", res);
        }
        if (close < open) {
            backtrack(open, close + 1, n, cur + ")", res);
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
};