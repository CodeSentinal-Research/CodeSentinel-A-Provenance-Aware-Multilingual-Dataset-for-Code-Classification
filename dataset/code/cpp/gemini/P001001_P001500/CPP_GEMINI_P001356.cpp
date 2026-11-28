#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
    int backtrack(const std::string& s, size_t idx, std::unordered_set<std::string>& seen) {
        if (idx == s.length()) return 0;
        int maxCount = 0;
        for (size_t i = idx + 1; i <= s.length(); i++) {
            std::string sub = s.substr(idx, i - idx);
            if (!seen.count(sub)) {
                seen.insert(sub);
                maxCount = std::max(maxCount, 1 + backtrack(s, i, seen));
                seen.erase(sub);
            }
        }
        return maxCount;
    }
public:
    int maxUniqueSplit(std::string s) {
        std::unordered_set<std::string> seen;
        return backtrack(s, 0, seen);
    }
};