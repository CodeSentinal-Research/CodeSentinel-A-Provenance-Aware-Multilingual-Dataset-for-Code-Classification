#include <string>
#include <vector>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::vector<int> m1(256, 0), m2(256, 0);
        for (size_t i = 0; i < s.length(); i++) {
            unsigned char c1 = s[i], c2 = t[i];
            if (m1[c1] != m2[c2]) return false;
            m1[c1] = i + 1;
            m2[c2] = i + 1;
        }
        return true;
    }
};