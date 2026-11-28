#include <string>

class Solution {
public:
    bool isDuck(std::string s) {
        size_t firstNonZero = s.find_first_not_of('0');
        if (firstNonZero == std::string::npos) return false;
        return s.find('0', firstNonZero) != std::string::npos;
    }
};
