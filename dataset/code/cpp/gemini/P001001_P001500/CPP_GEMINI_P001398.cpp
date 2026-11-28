#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<int> common(26, INT_MAX);

        for (const auto& w : words) {
            std::vector<int> count(26, 0);
            for (char c : w) count[c - 'a']++;
            for (int i = 0; i < 26; i++) common[i] = std::min(common[i], count[i]);
        }

        std::vector<std::string> res;
        for (int i = 0; i < 26; i++) {
            while (common[i]-- > 0) {
                res.push_back(std::string(1, 'a' + i));
            }
        }
        return res;
    }
};