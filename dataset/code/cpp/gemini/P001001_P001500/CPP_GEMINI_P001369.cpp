#include <vector>
#include <string>
#include <unordered_set>

class Solution {
    std::unordered_set<std::string> res;

    void backtrack(const std::string& s, int idx, int open, int close, int lRem, int rRem, std::string& cur) {
        if (idx == (int)s.length()) {
            if (lRem == 0 && rRem == 0) res.insert(cur);
            return;
        }

        char c = s[idx];
        if (c == '(' && lRem > 0) {
            backtrack(s, idx + 1, open, close, lRem - 1, rRem, cur);
        } else if (c == ')' && rRem > 0) {
            backtrack(s, idx + 1, open, close, lRem, rRem - 1, cur);
        }

        cur.push_back(c);
        if (c != '(' && c != ')') {
            backtrack(s, idx + 1, open, close, lRem, rRem, cur);
        } else if (c == '(') {
            backtrack(s, idx + 1, open + 1, close, lRem, rRem, cur);
        } else if (close < open) {
            backtrack(s, idx + 1, open, close + 1, lRem, rRem, cur);
        }
        cur.pop_back();
    }
public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        int lRem = 0, rRem = 0;
        for (char c : s) {
            if (c == '(') lRem++;
            else if (c == ')') {
                if (lRem > 0) lRem--;
                else rRem++;
            }
        }
        std::string cur = "";
        backtrack(s, 0, 0, 0, lRem, rRem, cur);
        return std::vector<std::string>(res.begin(), res.end());
    }
};