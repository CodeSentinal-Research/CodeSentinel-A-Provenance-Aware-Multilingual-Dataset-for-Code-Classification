#include <string>

class Solution {
public:
    std::string minWindow(std::string s1, std::string s2) {
        int m = s1.length(), n = s2.length();
        int minLen = m + 1, startIdx = -1;
        int i = 0, j = 0;

        while (i < m) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == n) {
                    int end = i;
                    j--;
                    while (j >= 0) {
                        if (s1[i] == s2[j]) j--;
                        i--;
                    }
                    i++;
                    j = 0;
                    if (end - i + 1 < minLen) {
                        minLen = end - i + 1;
                        startIdx = i;
                    }
                }
            }
            i++;
        }
        return startIdx != -1 ? s1.substr(startIdx, minLen) : "";
    }
};