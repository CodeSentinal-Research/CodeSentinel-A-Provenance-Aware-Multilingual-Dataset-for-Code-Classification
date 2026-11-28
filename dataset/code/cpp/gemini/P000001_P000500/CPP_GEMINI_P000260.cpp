#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    std::string to_lower(std::string str) {
        for (char& c : str) c = std::tolower(c);
        return str;
    }
};