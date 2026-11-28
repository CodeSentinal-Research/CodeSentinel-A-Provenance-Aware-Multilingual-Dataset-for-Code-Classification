#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s) {
        std::unordered_map<char, int> count;
        int l = 0, maxLen = 0;

        for (size_t r = 0; r < s.length(); r++) {
            count[s[r]]++;
            while (count.size() > 2) {
                if (--count[s[l]] == 0) count.erase(s[l]);
                l++;
            }
            maxLen = std::max(maxLen, (int)(r - l + 1));
        }
        return maxLen;
    }
};