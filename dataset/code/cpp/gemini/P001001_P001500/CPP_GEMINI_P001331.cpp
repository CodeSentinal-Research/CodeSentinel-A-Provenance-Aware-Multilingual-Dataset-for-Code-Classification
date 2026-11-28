#include <vector>
#include <string>

class Solution {
    void backtrack(const std::string& s, int idx, int dots, std::string cur, std::vector<std::string>& res) {
        if (dots == 4 && idx == (int)s.length()) {
            cur.pop_back();
            res.push_back(cur);
            return;
        }
        if (dots > 4) return;

        for (int l = 1; l <= 3; l++) {
            if (idx + l <= (int)s.length()) {
                std::string part = s.substr(idx, l);
                if ((part[0] != '0' || l == 1) && std::stoi(part) <= 255) {
                    backtrack(s, idx + l, dots + 1, cur + part + ".", res);
                }
            }
        }
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        backtrack(s, 0, 0, "", res);
        return res;
    }
};