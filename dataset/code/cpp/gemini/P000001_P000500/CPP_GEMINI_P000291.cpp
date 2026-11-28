#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        std::vector<int> c1(26, 0), c2(26, 0);
        for (char c : s1) c1[c - 'a']++;

        for (int i = 0; i < n2; i++) {
            c2[s2[i] - 'a']++;
            if (i >= n1) c2[s2[i - n1] - 'a']--;
            if (c1 == c2) return true;
        }
        return false;
    }
};