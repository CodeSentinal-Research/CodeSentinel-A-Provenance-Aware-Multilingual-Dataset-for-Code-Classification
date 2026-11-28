#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    std::string to_upper(std::string str) {
        for (char& c : str) c = std::toupper(c);
        return str;
    }
};