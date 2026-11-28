#include <cmath>
#include <string>

class Solution {
public:
    bool isArmstrong(int n) {
        if (n < 0) return false;
        std::string s = std::to_string(n);
        int k = s.size();
        long long sum = 0;
        for (char c : s) {
            sum += std::pow(c - '0', k);
        }
        return sum == n;
    }
};
