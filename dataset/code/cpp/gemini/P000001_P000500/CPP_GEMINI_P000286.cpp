#include <string>
#include <cctype>

class Solution {
public:
    std::string reverseOnlyLetters(std::string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (!std::isalpha(s[i])) i++;
            else if (!std::isalpha(s[j])) j--;
            else {
                std::swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};