#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        std::unordered_set<char> allow(allowed.begin(), allowed.end());
        int count = 0;
        for (const auto& w : words) {
            bool consistent = true;
            for (char c : w) {
                if (!allow.count(c)) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
};