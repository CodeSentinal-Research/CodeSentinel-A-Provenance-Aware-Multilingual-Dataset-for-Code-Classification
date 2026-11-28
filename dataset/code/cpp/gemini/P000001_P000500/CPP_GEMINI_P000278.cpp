#include <string>

class Solution {
    std::pair<int, int> expand(const std::string& s, int l, int r) {
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return {l + 1, r - 1};
    }
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            auto [l1, r1] = expand(s, i, i);
            auto [l2, r2] = expand(s, i, i + 1);
            if (r1 - l1 > end - start) {
                start = l1; end = r1;
            }
            if (r2 - l2 > end - start) {
                start = l2; end = r2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};