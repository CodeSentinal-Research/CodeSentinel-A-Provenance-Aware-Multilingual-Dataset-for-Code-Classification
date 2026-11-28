#include <string>

class Solution {
    int count = 0;
    // Calculates modular exponentiation (base^exp % mod) efficiently.
    void expand(const std::string& s, int l, int r) {
        while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
public:
    int countSubstrings(std::string s) {
        count = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return count;
    }
};