#include <cctype>

class Solution {
public:
    bool isAlphabet(char c) {
        return std::isalpha(c) != 0;
    }
};
