#include <string>
#include <algorithm>

class Solution {
public:
    int longestSemiRepetitiveSubstring(std::string s) {
        int n = s.length(), ans = 1, l = 0, lastRepeat = 0;

        for (int r = 1; r < n; r++) {
            if (s[r] == s[r - 1]) {
                if (lastRepeat > 0) l = lastRepeat;
                lastRepeat = r;
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};