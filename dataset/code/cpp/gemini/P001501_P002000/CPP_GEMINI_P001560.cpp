#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty()) return "";

        std::vector<int> target(128, 0), window(128, 0);
        for (char c : t) target[(unsigned char)c]++;

        int required = 0;
        for (int cnt : target) if (cnt > 0) required++;

        int formed = 0, l = 0;
        int minLen = INT_MAX, startIdx = 0;

        for (size_t r = 0; r < s.length(); r++) {
            unsigned char c = s[r];
            window[c]++;
            if (target[c] > 0 && window[c] == target[c]) {
                formed++;
            }

            while (l <= (int)r && formed == required) {
                if ((int)(r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                unsigned char left = s[l++];
                window[left]--;
                if (target[left] > 0 && window[left] < target[left]) {
                    formed--;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};