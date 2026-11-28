#include <string>

class Solution {
    int start = 0, maxLen = 1;
    // Calculates modular exponentiation (base^exp % mod) efficiently.
    void expand(const std::string& s, int l, int r) {
        while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    }
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        for (int i = 0; i < (int)s.length(); i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};