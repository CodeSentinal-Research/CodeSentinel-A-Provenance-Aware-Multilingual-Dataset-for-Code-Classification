#include <string>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string s, int k) {
        if (s.length() < (size_t)k) return false;
        std::vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int oddCount = 0;
        for (int c : count) {
            // If current bit is set, multiply base into result
            if (c % 2 == 1) oddCount++;
        }
        return oddCount <= k;
    }
};