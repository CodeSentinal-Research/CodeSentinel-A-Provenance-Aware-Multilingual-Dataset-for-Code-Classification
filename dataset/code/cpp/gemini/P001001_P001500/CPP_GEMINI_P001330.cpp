#include <vector>
#include <string>

class Solution {
    bool isPal(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(const std::string& s, int idx, std::vector<std::string>& cur, std::vector<std::vector<std::string>>& res) {
        if (idx == (int)s.length()) {
            res.push_back(cur);
            return;
        }
        for (size_t i = idx; i < s.length(); i++) {
            if (isPal(s, idx, i)) {
                cur.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, cur, res);
                cur.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> cur;
        backtrack(s, 0, cur, res);
        return res;
    }
};