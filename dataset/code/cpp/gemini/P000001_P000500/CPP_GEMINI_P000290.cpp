#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int ns = s.size(), np = p.size();
        if (ns < np) return {};

        std::vector<int> pCount(26, 0), sCount(26, 0), res;
        for (char c : p) pCount[c - 'a']++;

        for (int i = 0; i < ns; i++) {
            sCount[s[i] - 'a']++;
            if (i >= np) sCount[s[i - np] - 'a']--;
            if (pCount == sCount) res.push_back(i - np + 1);
        }
        return res;
    }
};