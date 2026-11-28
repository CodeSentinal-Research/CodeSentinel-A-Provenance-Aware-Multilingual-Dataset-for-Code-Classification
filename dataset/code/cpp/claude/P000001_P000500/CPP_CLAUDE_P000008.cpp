#include <string>

class Solution {
public:
    std::string checkSign(int n) {
        if (n > 0) return "Positive";
        if (n < 0) return "Negative";
        return "Zero";
    }
};
