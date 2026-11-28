#include <string>

class Solution {
public:
    bool areRotations(std::string s1, std::string s2) {
        if (s1.size() != s2.size()) return false;
        return (s1 + s1).find(s2) != std::string::npos;
    }
};