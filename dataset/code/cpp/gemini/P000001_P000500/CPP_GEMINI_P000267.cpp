#include <string>

class Solution {
public:
    std::string replace(std::string s, char c1, char c2) {
        for (char& c : s) {
            if (c == c1) c = c2;
        }
        return s;
    }
};