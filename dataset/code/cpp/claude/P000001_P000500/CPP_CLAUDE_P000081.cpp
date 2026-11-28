#include <cctype>

class Solution {
public:
    bool isDigit(char c) {
        return std::isdigit(c) != 0;
    }
};
