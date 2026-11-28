#include <string>

class Solution {
    bool backtrack(const std::string& s, int idx, long long prev, int count) {
        if (idx == (int)s.length()) return count >= 2;
        for (size_t i = idx + 1; i <= s.length(); i++) {
            if (i - idx > 18) break;
            long long val = std::stoll(s.substr(idx, i - idx));
            if (prev == -1 || val == prev - 1) {
                if (backtrack(s, i, val, count + 1)) return true;
            }
        }
        return false;
    }
public:
    bool splitString(std::string s) {
        return backtrack(s, 0, -1, 0);
    }
};