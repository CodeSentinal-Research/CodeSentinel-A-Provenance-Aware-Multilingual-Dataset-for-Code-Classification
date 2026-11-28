#include <string>
#include <algorithm>

class Solution {
public:
    std::string decToBinary(int n) {
        if (n == 0) return "0";
        std::string res = "";
        unsigned int un = n;
        while (un > 0) {
            res += (un % 2) ? '1' : '0';
            un /= 2;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
