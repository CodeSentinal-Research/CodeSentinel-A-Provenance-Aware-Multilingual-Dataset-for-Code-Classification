#include <string>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string stack = "";
        for (char c : num) {
            while (k > 0 && !stack.empty() && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }
        size_t start = stack.find_first_not_of('0');
        if (start == std::string::npos) return "0";
        return stack.substr(start);
    }
};