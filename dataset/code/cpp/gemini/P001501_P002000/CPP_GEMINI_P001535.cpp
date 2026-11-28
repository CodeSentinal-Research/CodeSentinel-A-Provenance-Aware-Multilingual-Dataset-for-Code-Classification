#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxFreq = 0, l = 0;

        for (size_t r = 0; r < s.length(); r++) {
            maxFreq = std::max(maxFreq, ++count[s[r] - 'A']);
            if ((int)(r - l + 1) - maxFreq > k) {
                count[s[l++] - 'A']--;
            }
        }
        return s.length() - l;
    }
};