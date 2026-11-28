#include <string>
#include <cctype>

class Solution {
public:
    std::string toggleCase(std::string s) {
        for (char& c : s) {
            if (std::isupper(c)) c = std::tolower(c);
            else if (std::islower(c)) c = std::toupper(c);
        }
        return s;
    }
};