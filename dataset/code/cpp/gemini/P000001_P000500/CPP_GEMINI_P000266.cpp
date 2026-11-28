#include <string>

class Solution {
public:
    std::string removeOccurrences(std::string s, char c) {
        std::string res = "";
        for (char ch : s) {
            if (ch != c) res += ch;
        }
        return res;
    }
};