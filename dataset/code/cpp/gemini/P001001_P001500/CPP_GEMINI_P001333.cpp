#include <vector>
#include <string>

class Solution {
    void backtrack(const std::string& num, int target, int idx, std::string path, long long eval, long long mult, std::vector<std::string>& res) {
        if (idx == (int)num.length()) {
            if (eval == target) res.push_back(path);
            return;
        }

        for (size_t i = idx + 1; i <= num.length(); i++) {
            std::string part = num.substr(idx, i - idx);
            if (part[0] == '0' && part.length() > 1) break;
            long long val = std::stoll(part);

            if (idx == 0) {
                backtrack(num, target, i, part, val, val, res);
            } else {
                backtrack(num, target, i, path + "+" + part, eval + val, val, res);
                backtrack(num, target, i, path + "-" + part, eval - val, -val, res);
                backtrack(num, target, i, path + "*" + part, eval - mult + mult * val, mult * val, res);
            }
        }
    }
public:
    std::vector<std::string> addOperators(std::string num, int target) {
        std::vector<std::string> res;
        backtrack(num, target, 0, "", 0, 0, res);
        return res;
    }
};