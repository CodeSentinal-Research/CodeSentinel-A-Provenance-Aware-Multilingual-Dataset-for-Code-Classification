#include <string>
#include <algorithm>

class Solution {
public:
    int countBinarySubstrings(std::string s) {
        int prev = 0, cur = 1, ans = 0;
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                ans += std::min(prev, cur);
                prev = cur;
                cur = 1;
            }
        }
        return ans + std::min(prev, cur);
    }
};