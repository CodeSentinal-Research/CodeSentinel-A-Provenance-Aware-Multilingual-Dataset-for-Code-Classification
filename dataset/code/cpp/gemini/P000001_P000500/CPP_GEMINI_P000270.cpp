#include <string>
#include <cctype>

class Solution {
public:
    std::string capitalize(std::string s) {
        bool newWord = true;
        for (char& c : s) {
            if (std::isspace(c)) {
                newWord = true;
            } else if (newWord) {
                c = std::toupper(c);
                newWord = false;
            }
        }
        return s;
    }
};