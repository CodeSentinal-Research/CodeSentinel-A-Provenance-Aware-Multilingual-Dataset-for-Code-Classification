#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int wordCount(std::vector<std::string>& startWords, std::vector<std::string>& targetWords) {
        std::unordered_set<int> seen;
        for (const auto& w : startWords) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            seen.insert(mask);
        }

        int ans = 0;
        for (const auto& w : targetWords) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            for (char c : w) {
                if (seen.count(mask ^ (1 << (c - 'a')))) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};