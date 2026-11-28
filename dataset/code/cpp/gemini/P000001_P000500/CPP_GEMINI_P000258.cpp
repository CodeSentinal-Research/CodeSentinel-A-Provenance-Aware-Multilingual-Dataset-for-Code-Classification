#include <string>
#include <algorithm>

class Solution {
public:
    std::string sort(std::string s) {
        std::sort(s.begin(), s.end());
        return s;
    }
};