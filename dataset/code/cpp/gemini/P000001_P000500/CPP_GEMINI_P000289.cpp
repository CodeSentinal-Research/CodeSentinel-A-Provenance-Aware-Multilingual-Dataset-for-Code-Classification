#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxFreq = 0, l = 0;

        for (int r = 0; r < (int)s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = std::max(maxFreq, count[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }
        }
        return (int)s.size() - l;
    }
};