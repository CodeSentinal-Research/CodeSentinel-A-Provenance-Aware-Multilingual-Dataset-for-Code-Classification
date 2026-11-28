#include <vector>
#include <string>
#include <cctype>

class Solution {
    bool match(const std::string& q, const std::string& pattern) {
        size_t j = 0;
        for (char c : q) {
            if (j < pattern.length() && c == pattern[j]) {
                j++;
            } else if (std::isupper(c)) {
                return false;
            }
        }
        return j == pattern.length();
    }
public:
    std::vector<bool> camelMatch(std::vector<std::string>& queries, std::string pattern) {
        std::vector<bool> res;
        for (const auto& q : queries) {
            res.push_back(match(q, pattern));
        }
        return res;
    }
};