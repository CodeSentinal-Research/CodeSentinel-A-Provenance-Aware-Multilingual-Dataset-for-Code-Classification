#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0, match = 0, starIdx = -1;
        int sLen = s.length(), pLen = p.length();
        while (sIdx < sLen) {
            if (pIdx < pLen && (p[pIdx] == '?' || s[sIdx] == p[pIdx])) {
                sIdx++;
                pIdx++;
            } else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            } else if (starIdx != -1) {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            } else {
                return false;
            }
        }
        while (pIdx < pLen && p[pIdx] == '*') pIdx++;
        return pIdx == pLen;
    }
};