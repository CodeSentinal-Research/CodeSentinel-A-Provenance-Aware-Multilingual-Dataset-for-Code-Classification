#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::unordered_set<std::string> seen, res;
        for (size_t i = 0; i + 10 <= s.length(); i++) {
            std::string sub = s.substr(i, 10);
            if (seen.count(sub)) res.insert(sub);
            seen.insert(sub);
        }
        return std::vector<std::string>(res.begin(), res.end());
    }
};