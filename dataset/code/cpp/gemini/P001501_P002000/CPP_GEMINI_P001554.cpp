#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> last(256, -1);
        int l = 0, maxLen = 0;

        for (size_t r = 0; r < s.length(); r++) {
            unsigned char c = s[r];
            if (last[c] >= l) {
                l = last[c] + 1;
            }
            last[c] = r;
            maxLen = std::max(maxLen, (int)(r - l + 1));
        }
        return maxLen;
    }
};