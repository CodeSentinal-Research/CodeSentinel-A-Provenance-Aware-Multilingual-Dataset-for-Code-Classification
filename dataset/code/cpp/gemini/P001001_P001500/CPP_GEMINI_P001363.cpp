#include <vector>
#include <string>

class Solution {
    void backtrack(int n, std::string cur, std::vector<std::string>& res) {
        if ((int)cur.length() == n) {
            res.push_back(cur);
            return;
        }
        backtrack(n, cur + "1", res);
        if (cur.empty() || cur.back() != '0') {
            backtrack(n, cur + "0", res);
        }
    }
public:
    std::vector<std::string> validStrings(int n) {
        std::vector<std::string> res;
        backtrack(n, "", res);
        return res;
    }
};