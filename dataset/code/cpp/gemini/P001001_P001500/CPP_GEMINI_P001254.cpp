#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> strs;
        for (int n : nums) strs.push_back(std::to_string(n));
        std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0";
        std::string res = "";
        for (const auto& s : strs) res += s;
        return res;
    }
};