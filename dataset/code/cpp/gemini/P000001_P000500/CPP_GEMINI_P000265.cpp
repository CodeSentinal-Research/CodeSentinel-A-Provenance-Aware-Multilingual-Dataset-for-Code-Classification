#include <string>
#include <unordered_set>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::unordered_set<char> seen;
        std::string res = "";
        for (char c : s) {
            if (seen.insert(c).second) res += c;
        }
        return res;
    }
};