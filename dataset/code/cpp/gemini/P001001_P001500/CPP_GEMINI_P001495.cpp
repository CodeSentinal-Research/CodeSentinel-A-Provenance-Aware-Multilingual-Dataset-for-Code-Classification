#include <string>

class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        size_t j = 0;
        for (size_t i = 0; i < s.length() && j < t.length(); i++) {
            if (s[i] == t[j]) j++;
        }
        return t.length() - j;
    }
};