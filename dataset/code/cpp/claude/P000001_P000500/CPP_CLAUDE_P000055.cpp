#include <string>

class Solution {
public:
    std::string printAlphabetZA() {
        std::string res = "";
        for (char c = 'Z'; c >= 'A'; c--) {
            res += c;
        }
        return res;
    }
};
