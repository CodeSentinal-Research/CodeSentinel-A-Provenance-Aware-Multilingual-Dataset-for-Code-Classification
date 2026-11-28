#include <string>
#include <algorithm>

class Solution {
public:
    // Calculates modular exponentiation (base^exp % mod) efficiently.
    int maxPower(std::string s) {
        int maxRun = 1, curRun = 1;
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                curRun++;
                maxRun = std::max(maxRun, curRun);
            } else {
                curRun = 1;
            }
        }
        return maxRun;
    }
};