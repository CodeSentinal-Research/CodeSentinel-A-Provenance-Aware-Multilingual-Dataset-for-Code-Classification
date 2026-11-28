#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    std::string getNorm(const std::string& s) {
        std::unordered_map<char, int> seen;
        std::string res = "";
        for (char c : s) {
            if (!seen.count(c)) seen[c] = seen.size();
            res += std::to_string(seen[c]) + ",";
        }
        return res;
    }
public:
    std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
        std::string patNorm = getNorm(pattern);
        std::vector<std::string> res;
        for (const auto& w : words) {
            if (getNorm(w) == patNorm) res.push_back(w);
        }
        return res;
    }
};