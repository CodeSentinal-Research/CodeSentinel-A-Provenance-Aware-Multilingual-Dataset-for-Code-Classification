#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return "";
        std::vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int missing = t.size();
        int start = 0, minLen = INT_MAX;
        int i = 0;

        for (int j = 0; j < (int)s.size(); j++) {
            if (need[s[j]] > 0) missing--;
            need[s[j]]--;

            if (missing == 0) {
                while (i < j && need[s[i]] < 0) {
                    need[s[i]]++;
                    i++;
                }
                if (j - i + 1 < minLen) {
                    start = i;
                    minLen = j - i + 1;
                }
                need[s[i]]++;
                missing++;
                i++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};