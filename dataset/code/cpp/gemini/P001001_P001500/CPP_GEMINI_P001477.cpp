#include <string>

class Solution {
    std::string build(const std::string& s) {
        std::string res = "";
        for (char c : s) {
            if (c != '#') res.push_back(c);
            else if (!res.empty()) res.pop_back();
        }
        return res;
    }
public:
    bool backspaceCompare(std::string s, std::string t) {
        return build(s) == build(t);
    }
};