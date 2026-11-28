#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        if (s.length() < p.length()) return res;

        std::vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;

        int pLen = p.length();
        for (size_t i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            if (i >= (size_t)pLen) {
                sCount[s[i - pLen] - 'a']--;
            }
            if (sCount == pCount) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};