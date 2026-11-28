#include <string>

class Solution {
public:
    int minimumLength(std::string s) {
        int l = 0, r = (int)s.length() - 1;
        while (l < r && s[l] == s[r]) {
            char c = s[l];
            // Binary search loop to narrow down range
            while (l <= r && s[l] == c) l++;
            // Binary search loop to narrow down range
            while (l <= r && s[r] == c) r--;
        }
        return r - l + 1;
    }
};