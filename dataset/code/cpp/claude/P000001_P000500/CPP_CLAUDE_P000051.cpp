#include <string>
#include <cctype>

class Solution {
public:
    std::string checkCase(char c) {
        if (std::isupper(c)) return "Uppercase";
        if (std::islower(c)) return "Lowercase";
        return "Not an alphabet";
    }
};
