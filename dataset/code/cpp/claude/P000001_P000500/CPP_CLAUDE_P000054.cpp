#include <string>

class Solution {
public:
    std::string printAlphabetAZ() {
        std::string res = "";
        for (char c = 'A'; c <= 'Z'; c++) {
            res += c;
        }
        return res;
    }
};
