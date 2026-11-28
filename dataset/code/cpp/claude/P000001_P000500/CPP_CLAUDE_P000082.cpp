#include <cctype>

class Solution {
public:
    bool isSpecial(char c) {
        return !std::isalnum(c) && !std::isspace(c);
    }
};
