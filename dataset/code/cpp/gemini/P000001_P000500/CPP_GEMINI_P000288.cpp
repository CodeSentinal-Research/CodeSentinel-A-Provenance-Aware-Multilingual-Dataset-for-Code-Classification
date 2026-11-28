#include <string>

class Solution {
    bool isPali(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
public:
    bool validPalindrome(std::string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isPali(s, i + 1, j) || isPali(s, i, j - 1);
            }
            i++; j--;
        }
        return true;
    }
};