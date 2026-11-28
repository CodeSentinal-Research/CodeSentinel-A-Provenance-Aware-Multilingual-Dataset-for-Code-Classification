#include <string>

class Solution {
public:
    int binaryToDecimal(std::string b) {
        int res = 0;
        for (char c : b) {
            res = res * 2 + (c - '0');
        }
        return res;
    }
};
