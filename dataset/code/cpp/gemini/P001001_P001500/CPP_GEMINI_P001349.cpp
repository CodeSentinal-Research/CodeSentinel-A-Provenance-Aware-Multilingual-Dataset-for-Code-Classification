#include <string>
#include <vector>

class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        std::string res = "";
        std::vector<int> stack;
        for (size_t i = 0; i <= pattern.length(); i++) {
            stack.push_back(i + 1);
            if (i == pattern.length() || pattern[i] == 'I') {
                while (!stack.empty()) {
                    res += std::to_string(stack.back());
                    stack.pop_back();
                }
            }
        }
        return res;
    }
};